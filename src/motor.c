#include "motor.h"



/* Device structs*/
static const struct pwm_dt_spec pwm = PWM_DT_SPEC_GET_BY_IDX(DT_NODELABEL(motor), 0);
static const struct gpio_dt_spec forward_pin = GPIO_DT_SPEC_GET_BY_IDX(DT_NODELABEL(motor_pins),gpios,0);
static const struct gpio_dt_spec backward_pin = GPIO_DT_SPEC_GET_BY_IDX(DT_NODELABEL(motor_pins),gpios,1);
const struct device *const dev = DEVICE_DT_GET(DT_ALIAS(qdec0));

/* Global variables for velocity*/
static uint32_t current_rpm = 0;

static int16_t prev_pulse_count = 0;
static double velocity = 0.0;

/* Timer struct*/
static struct k_timer calculate_velocity_tim;

/* Velocity calc timer*/
static void calculate_velocity_tim_callback(struct k_timer *tim)
{
	struct sensor_value val;
	if (sensor_sample_fetch(dev) != 0)
	{
		printk("Failed to fetch sample\n");
	}
	else
	{
		sensor_channel_get(dev, SENSOR_CHAN_ROTATION, &val);
		velocity = (((double)(val.val1 - prev_pulse_count))/SHAFT_REVOLUTION_RATIO)*(60.0/TIME_BASIS);
        current_rpm = (uint32_t)velocity;
		prev_pulse_count = val.val1;
        //printk("timer working %f\n",velocity);
	}
}


static bool is_direction_pins_ready(){
    if((!device_is_ready(forward_pin.port)) || (!device_is_ready(forward_pin.port))){
        printk("Error to config direction pin");
        return false;
    }else{
        if((gpio_pin_configure_dt(&forward_pin,GPIO_OUTPUT) != 0) ||(gpio_pin_configure_dt(&backward_pin,GPIO_OUTPUT) != 0)){
            printk("Error to config direction pin output");
            return false;
        }else{
            printk("Direction pin enabled");
            return true;

        }
        
    }
}

static bool is_pwm_ready()
{
    if (device_is_ready(pwm.dev))
    {
        printk("Looks like he is ready!!\nDevice channel: {%d}\nDevice period: {%d}\n", pwm.channel, pwm.period);
        return true;
    }
    else
    {
        printk("F is not ready yet\n");
        return false;
    }

}


// TODO: Handle error and send to caller
bool set_motor_direction_forward(){
    gpio_pin_set_dt(&backward_pin,GPIO_ACTIVE_LOW);
    gpio_pin_set_dt(&forward_pin,GPIO_ACTIVE_HIGH);
    return true;
}

bool set_motor_direction_backward(){
    gpio_pin_set_dt(&backward_pin,GPIO_ACTIVE_HIGH);
    gpio_pin_set_dt(&forward_pin,GPIO_ACTIVE_LOW);
    return true;
}

bool init_motor()
{
    if ((!is_pwm_ready()) || (!is_direction_pins_ready()))
    {
        printk("PWM Init Error");
        return false;
    }
    else
    {
        k_timer_init(&calculate_velocity_tim, calculate_velocity_tim_callback, NULL);
	    k_timer_start(&calculate_velocity_tim,TIMER_PERIOD_AND_DURATION,TIMER_PERIOD_AND_DURATION);
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