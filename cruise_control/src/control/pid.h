#pragma once

#include "motor.h"
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <math.h>


#define KP 10.0f
#define KI 5.0f
#define KD 0.01f

#define INTEGRAL_WINDUP_LIMIT 5000

#define INTERVAL_PERIOD K_MSEC(10)
#define INTERVAL_PERIOD_FP 0.01f

#define MAX_OUTPUT PWM_SIGNAL_FREQUENCY_NS
#define MIN_OUTPUT 0

#define ERROR_TOLERANCE 2


struct pid
{
    float integral;
    float derivative;
    float proportional;
    float pid_output;
    int32_t error;
    int32_t prev_error;
    uint32_t target;
    bool saturation;
};









void set_pid_target_rpm(uint32_t target);
void start_pid_controller();