#pragma once

#include "motor.h"
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <math.h>


#define KP 900.00
#define KI 90.00
#define KD 50.00

#define INTEGRAL_WINDUP_LIMIT 5000

#define INTERVAL_PERIOD K_MSEC(10)
#define INTERVAL_PERIOD_FP 0.01

#define MAX_OUTPUT PWM_SIGNAL_FREQUENCY_NS
#define MIN_OUTPUT 0

void set_pid_target_rpm(int16_t target);
void start_pid_controller();