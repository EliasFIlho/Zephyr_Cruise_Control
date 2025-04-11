#pragma once

#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>


#define DEVICE_FREQUENCY_HZ 80000000
#define PWM_SIGNAL_FREQUENCY_NS PWM_HZ(60)
#define PWM_POLARITY_NORMAL (0 << 0)

#define PULSE_REVOLUTION_RATIO 11
#define GEAR_RATIO 4.4
#define SHAFT_REVOLUTION_RATIO (PULSE_REVOLUTION_RATIO*GEAR_RATIO)

#define TIMER_PERIOD_AND_DURATION K_MSEC(20)
#define TIME_BASIS 0.02


bool init_motor();
bool set_pwm_duty_period(uint32_t period_ns);
bool set_pwm_pulse_output_percent(uint8_t pulse_percent);
bool set_motor_direction_backward();
bool set_motor_direction_forward();
uint32_t get_current_rpm();