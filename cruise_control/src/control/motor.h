#pragma once

#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include "moving_avg.h"

#define PWM_SIGNAL_FREQUENCY_NS PWM_HZ(50000)
#define PWM_POLARITY_NORMAL (0 << 0)




void init_motor();
bool set_pwm_duty_period(uint32_t period_ns);
bool set_pwm_pulse_output_percent(uint8_t pulse_percent);
bool set_motor_direction_backward();
bool set_motor_direction_forward();
