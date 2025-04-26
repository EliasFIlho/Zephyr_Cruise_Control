#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include "control/motor.h"
#include <stdlib.h>
#include "pid.h"


int main(void)
{

    if (init_motor())
    {
        printk("PWM started");
    }
    else
    {
        printk("Error to start pwm");
    }

    //set_motor_direction_forward();
    set_motor_direction_backward();
    set_pwm_pulse_output_percent(0);
    
    printk("Call PID start controller");
    start_pid_controller();
    int target = 0;
    set_pwm_duty_period(0);
    while (1)
    {
        k_sleep(K_USEC(50));
    }

    return 0;
}
