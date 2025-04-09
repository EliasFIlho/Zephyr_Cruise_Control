#include "signal_capture.h"

static const struct pwm_dt_spec pwm = PWM_DT_SPEC_GET_BY_IDX(DT_NODELABEL(motor), 0);
static const struct pwm_dt_spec cap = PWM_DT_SPEC_GET_BY_IDX(DT_NODELABEL(motor), 1);


static uint32_t current_rpm = 0;

static void capture_handler(const struct device *dev, uint32_t channel, uint32_t period_cycles, uint32_t pulse_cycles, int status, void *user_data)
{
    if (status != 0)
    {
        printk("Error to capture - status: [%d]", status);
    }
    else
    {

        double frequency = 1.0 / ((double)period_cycles / (double)DEVICE_FREQUENCY_HZ);
        double rpm = (frequency * 60.0) / (SHAFT_REVOLUTION_RATIO);
        // double duty = ((double)pulse_cycles / (double)period_cycles) * 100.0;
        current_rpm = (uint32_t)rpm;
        printk("RPM from cap 0: %f\n", rpm);
    }
}

static bool is_pwm_ready()
{
    if (device_is_ready(pwm.dev))
    {
        printk("Looks like he is ready!!\nDevice channel: {%d}\nDevice period: {%d}\n", pwm.channel, pwm.period);
    }
    else
    {
        printk("F is not ready yet\n");
        return false;
    }

    if (device_is_ready(cap.dev))
    {
        printk("Looks like out is ready!!\nDevice channel: {%d}\nDevice period: {%d}\n", cap.channel, cap.period);
    }
    else
    {
        printk("F out is not ready yet\n");
        return false;
    }
    return true;
}

bool init_pwms()
{
    if (!is_pwm_ready())
    {
        printk("PWM Init Error");
        return false;
    }
    else
    {
        int ret = pwm_configure_capture(cap.dev, cap.channel, (PWM_CAPTURE_TYPE_BOTH | PWM_CAPTURE_MODE_CONTINUOUS), capture_handler, NULL);
        if (ret != 0)
        {
            return false;
        }
        else
        {
            // no if without else
        }

        ret = pwm_enable_capture(cap.dev, cap.channel);
        if (ret != 0)
        {
            return false;
        }
        else
        {
            // no if without else
        }

        return true;
    }   
}

bool set_pwm_duty_period(uint32_t period_ns)
{
    if (period_ns > PWM_SIGNAL_FREQUENCY_NS)
    {
        return false;
    }
    else
    {
        int err;
        err = pwm_set(pwm.dev, pwm.channel, PWM_SIGNAL_FREQUENCY_NS, period_ns, PWM_POLARITY_NORMAL);
        if (err != 0)
        {
            printk("Error to set pwm out: Err{%d}\n", err);
            return false;
        }
        else
        {
            return true;
        }
    }
}
bool set_pwm_pulse_output_percent(uint8_t pulse_percent)
{
    int pulse_value;
    if (pulse_percent > 100)
    {
        return false;
    }
    else
    {
        pulse_value = (pulse_percent * PWM_SIGNAL_FREQUENCY_NS) / 100;
    }
    int err;
    err = pwm_set(pwm.dev, pwm.channel, PWM_SIGNAL_FREQUENCY_NS, pulse_value, PWM_POLARITY_NORMAL);
    if (err != 0)
    {
        printk("Error to set pwm out: Err{%d}\n", err);
        return false;
    }
    else
    {
        return true;
    }
}
uint32_t get_current_rpm(){
    return current_rpm;
}