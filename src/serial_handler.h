#pragma once
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/sys/printk.h>
#include <string.h>


extern struct k_msgq uart_queue; 

struct buffer {
    uint8_t buffer[50];
    uint8_t pos;
};

bool serial_init();