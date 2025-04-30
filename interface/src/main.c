#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include "serial/serial_handler.h"
#include <stdlib.h>
#include "can/can.h"

static const struct device *uart_dev = DEVICE_DT_GET(UART_DEVICE_NODE);
static const struct device *const can_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_canbus));

K_MSGQ_DEFINE(uart_queue, q_msg_size, 10, 1);
K_MSGQ_DEFINE(can_queue, sizeof(struct plot_print), 10, 1);

int main(void)
{
    struct plot_print data = {0};
    int target = 0;

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
    enable_rx_callback_filter(can_dev, TARGET_CONTROL_ID);


    while (1)
    {
        if (k_msgq_get(&uart_queue, &tx_buf, K_NO_WAIT) == 0)
        {
            target = atoi(tx_buf);
            if (target < 0)
            {
                target *= -1;
            }
            send_can_control_data(can_dev, (uint16_t)target);
        }
        if (k_msgq_get(&can_queue, &data, K_NO_WAIT) == 0)
        {
            printk("%d,%d\n", data.rpm, data.target);
        }
        k_msleep(50);
    }

    return 0;
}
