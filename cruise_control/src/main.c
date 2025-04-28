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
K_MSGQ_DEFINE(can_tx_queue, q_msg_tx_size, 3, 1);

int main(void)
{
    // init services
    init_motor(); 
    init_encoder_read();
    init_pid_controller();
    //init_can(can_dev);


    uint16_t target = 0;


    while (1)
    {
        if(k_msgq_get(&can_rx_queue, &target, K_NO_WAIT) == 0){
            set_pid_target_rpm(target);
        }


        // Perform general application code herer
        k_sleep(K_MSEC(5));
    }

    return 0;
}
