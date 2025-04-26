#pragma once

#include <stdint.h>


#define SAMPLE_NUM 10

typedef struct {
    uint32_t sample;
    uint32_t sample_buffer[SAMPLE_NUM];
    uint32_t filtered_value;
    uint32_t sum;
    uint8_t buffer_position;


}moving_avg_t;


void apply_filter(moving_avg_t *filter);
