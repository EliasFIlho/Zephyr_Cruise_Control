#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include "serial/serial_handler.h"
#include <stdlib.h>
#include "can/can.h"


static const struct device *uart_dev = DEVICE_DT_GET(UART_DEVICE_NODE);
static const struct device *const can_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_canbus));


K_MSGQ_DEFINE(uart_queue, q_msg_size, 10, 1);

int main(void)
{

    char tx_buf[50];
    if (serial_init(uart_dev))
    {
        printk("Serial started");
    }
    else
    {
        printk("Serial got some error\n");
    }

    init_can(can_dev);
    enable_rx_callback_filter(can_dev,TARGET_CONTROL_ID);

    int target = 0;

    while (1)
    {
        if (k_msgq_get(&uart_queue, &tx_buf, K_NO_WAIT) == 0)
        {
            target = atoi(tx_buf);
            if(target < 0){
                target *= -1;
            }
            send_can_control_data(can_dev,(uint16_t)target);

        }
        k_sleep(K_USEC(50));
    }

    return 0;
}
