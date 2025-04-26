#pragma once

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>
#include <zephyr/drivers/can.h>
#include "../control/pid.h"



#define TARGET_CONTROL_ID 0x123
#define MOTOR_INFO_ID 0x543



void rx_callback_function(const struct device *dev, struct can_frame *frame, void *user_data);
//bool send_can_control_data(struct device *can_iface, uint16_t target);
void enable_rx_callback_filter(struct device *can_iface,uint16_t ID);
void init_can(struct device *can_iface);