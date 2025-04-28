#pragma once

#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>
#include "moving_avg.h"


#define PULSE_REVOLUTION_RATIO 11
#define GEAR_RATIO 4.4
#define SHAFT_REVOLUTION_RATIO (PULSE_REVOLUTION_RATIO*GEAR_RATIO)



#define TIME_BASIS 0.1


#define ENCODER_READ_THREAD_STACK 1024
#define ENCODER_READ_THREAD_PRIORITY 5
#define ENCODER_THREAD_PERIOD_MS 100
#define ENCODER_THREAD_OPTIONS (K_FP_REGS | K_ESSENTIAL)


#define q_msg_rpm_size 32

extern struct k_msgq encoder_rpm_queue; 
k_tid_t init_encoder_read();
int32_t get_current_rpm();