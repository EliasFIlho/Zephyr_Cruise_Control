#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include "control/motor.h"
#include <stdlib.h>
#include "pid.h"
#include "can/can.h"
#include "control/encoder.h"

static const struct device *can_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_canbus));

K_MSGQ_DEFINE(can_rx_queue, q_msg_rx_size, 3, 1);
K_MSGQ_DEFINE(can_tx_queue, sizeof(struct control_info), 3, 1);
K_MSGQ_DEFINE(encoder_rpm_queue, q_msg_rpm_size, 3, 1);

int main(void)
{
    // init services
    init_motor();
    init_encoder_read();
    init_pid_controller();
    init_can(can_dev);

    uint16_t target = 0;
    uint16_t rpm = 0;
    struct control_info motor_data = {0};

    while (1)
    {
        // Read for incoming control values from CAN bus
        if (k_msgq_get(&can_rx_queue, &target, K_NO_WAIT) == 0)
        {
            set_pid_target_rpm(target);
        }
        // Read for current rpm value from encoder thread
        // Send rpm value to PID thread (This will be a test to select a msg queue or a shared memory block between encoder and PID)
        if (k_msgq_get(&encoder_rpm_queue, &rpm, K_NO_WAIT) == 0)
        {
            set_pid_current_rpm(rpm);
        }
        // Read for incoming control infos to be send through CAN bus
        if (k_msgq_get(&can_tx_queue, &motor_data, K_NO_WAIT) == 0)
        {
            send_motor_info_frame(can_dev, &motor_data);
        }

        k_sleep(K_MSEC(5));
    }

    return 0;
}
