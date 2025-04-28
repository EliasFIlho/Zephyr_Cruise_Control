#include "encoder.h"

const struct device *const dev = DEVICE_DT_GET(DT_ALIAS(qdec0));

moving_avg_t filter = {
    .sample_buffer = {0},
    .buffer_position = 0,
    .sample = 0,
    .filtered_value = 0,
    .sum = 0};



K_THREAD_STACK_DEFINE(ENCODER_STACK_AREA, ENCODER_READ_THREAD_STACK);
struct k_thread encoder_thread;



/*Encoder thread function*/

//TODO: Create a queue to send current velocity to main
static void calculate_velocity_thread(void *, void *, void *)
{
    int32_t current_rpm = 0;
    struct sensor_value val;
    int16_t delta_count;
    double velocity = 0.0;
    int16_t prev_pulse_count = 0;


    while (1)
    {

        if (sensor_sample_fetch(dev) != 0)
        {
            printk("Failed to fetch sample\n");
        }
        else
        {
            sensor_channel_get(dev, SENSOR_CHAN_ROTATION, &val);
            delta_count = val.val1 - prev_pulse_count;
            if (delta_count < 0)
            {
                delta_count *= -1;
                filter.sample = delta_count;
            }
            else
            {
                filter.sample = delta_count;
            }
            apply_filter(&filter);

            velocity = ((double)(filter.filtered_value)) / TIME_BASIS;
            current_rpm = (int32_t)((velocity / SHAFT_REVOLUTION_RATIO) * 60);
            k_msgq_put(&encoder_rpm_queue,&current_rpm,K_NO_WAIT);
            prev_pulse_count = val.val1;
        }

        k_msleep(ENCODER_THREAD_PERIOD_MS);
    }
}


k_tid_t init_encoder_read()
{
    return k_thread_create(&encoder_thread, ENCODER_STACK_AREA,
                    K_THREAD_STACK_SIZEOF(ENCODER_STACK_AREA),
                    calculate_velocity_thread,
                    NULL,
                    NULL,
                    NULL,
                    ENCODER_READ_THREAD_PRIORITY, ENCODER_THREAD_OPTIONS, K_NO_WAIT);
}


