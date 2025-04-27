#pragma once

#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>
#include "moving_avg.h"


#define PULSE_REVOLUTION_RATIO 11
#define GEAR_RATIO 4.4
#define SHAFT_REVOLUTION_RATIO (PULSE_REVOLUTION_RATIO*GEAR_RATIO)

#define TIMER_PERIOD_AND_DURATION K_MSEC(100)
#define TIME_BASIS 0.1


void init_encoder_tim();
int32_t get_current_rpm();