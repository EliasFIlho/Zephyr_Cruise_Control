#pragma once

#include "motor.h"
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <math.h>


#define KP 300
#define KI 50
#define KD 0.02
#define INTERVAL_PERIOD K_MSEC(20)
#define INTERVAL_PERIOD_FP 0.02

#define MAX_OUTPUT PWM_SIGNAL_FREQUENCY_NS
#define MIN_OUTPUT 0

void set_pid_target_rpm(int16_t target);
void start_pid_controller();