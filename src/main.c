#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include "serial/serial_handler.h"
#include "control/motor.h"
#include <stdlib.h>
#include "pid.h"

#define q_msg_size 32

K_MSGQ_DEFINE(uart_queue, q_msg_size, 10, 4);

int main(void)
{

    char tx_buf[50];
    if (serial_init())
    {
        printk("Serial started");
    }
    else
    {
        printk("Serial got some error\n");
    }

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
        if (k_msgq_get(&uart_queue, &tx_buf, K_NO_WAIT) == 0)
        {
            target = atoi(tx_buf);
            if(target < 0){
                target *= -1;
            }
            set_pid_target_rpm(target);
        };
        k_sleep(K_USEC(50));
    }

    return 0;
}
