#include "moving_avg.h"


void apply_filter(moving_avg_t *filter) {
    filter->sum -= filter->sample_buffer[filter->buffer_position];
    filter->sum += filter->sample;
    filter->sample_buffer[filter->buffer_position] = filter->sample;
    filter->buffer_position = (filter->buffer_position + 1) % SAMPLE_NUM;
    filter->filtered_value = filter->sum / SAMPLE_NUM;
}