#include "encoder.h"

const struct device *const dev = DEVICE_DT_GET(DT_ALIAS(qdec0));

moving_avg_t filter = {
    .sample_buffer = {0},
    .buffer_position = 0,
    .sample = 0,
    .filtered_value = 0,
    .sum = 0};

/* Global variables for velocity*/
volatile _Atomic int32_t current_rpm = 0;
static int16_t prev_pulse_count = 0;


/* Timer struct*/
static struct k_timer calculate_velocity_tim;

/* Velocity calc timer*/


// This timer runs in an ISR background and i cant fetch/get sensor data due to mutex operation so...
// TODO: Change this SW Timer to a dedicated thread
// I've only see this issue bcs of the CONFIG_ASSERT in prj.conf
static void calculate_velocity_tim_callback(struct k_timer *tim)
{
    struct sensor_value val;
    int16_t delta_count;
    double velocity = 0.0;

    if (sensor_sample_fetch(dev) != 0)
    {
        //printk("Failed to fetch sample\n");
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
        prev_pulse_count = val.val1;
        // printk("Delta | %d | Current RPM: | %d |\n",filter.filtered_value,current_rpm);
    }
}

void init_encoder_tim()
{
    k_timer_init(&calculate_velocity_tim, calculate_velocity_tim_callback, NULL);
    k_timer_start(&calculate_velocity_tim, TIMER_PERIOD_AND_DURATION, TIMER_PERIOD_AND_DURATION);
}

int32_t get_current_rpm()
{
    return current_rpm;
}