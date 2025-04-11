#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include "serial_handler.h"
#include "motor.h"
#include <stdlib.h>

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

    set_pwm_pulse_output_percent(0);
    uint32_t rpm = 0;

    while (1)
    {
        if (k_msgq_get(&uart_queue, &tx_buf, K_NO_WAIT) == 0)
        {
            int duty = atoi(tx_buf);
            set_motor_direction_forward();
            //set_motor_direction_backward();
            set_pwm_pulse_output_percent(duty);
        };
        rpm = get_current_rpm();
        printk("%d\n", rpm);
        k_sleep(K_MSEC(50));
    }

    return 0;
}
