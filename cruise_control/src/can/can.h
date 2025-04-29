#pragma once

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>
#include <zephyr/drivers/can.h>
#include "../control/pid.h"



#define TARGET_CONTROL_ID 0x123
#define MOTOR_INFO_ID 0x543

#define q_msg_rx_size 16


extern struct k_msgq can_rx_queue; 


void rx_callback_function(const struct device *dev, struct can_frame *frame, void *user_data);
void init_can(struct device *can_iface);
bool send_motor_info_frame(struct device *can_iface, struct control_info *motor_info);