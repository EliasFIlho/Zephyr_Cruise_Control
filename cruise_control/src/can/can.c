#include "can.h"

static const struct can_filter target_control_filter = {
    .flags = 0,
    .id = TARGET_CONTROL_ID,
    .mask = 0};


static struct can_frame motor_info_frame = {
    .flags = 0,
    .id = TARGET_CONTROL_ID,
    .dlc = 8,
    .data = {0}};


void rx_callback_function(const struct device *dev, struct can_frame *frame, void *user_data)
{
    printk("\nFRAME ID: [%d]\n", frame->id);
    printk("FRAME DLC: [%d]\n", frame->dlc);
    uint16_t target = (frame->data[0] << 8) | (frame->data[1]);
    printk("Target: [%d]\n",target);
    //set_pid_target_rpm(target);
    for (int i = 0; i < frame->dlc; i++)
    {
        printk("Frame[%d]: %d ", i, frame->data[i]);
    }
}

// bool send_can_motor_data(struct device *can_iface, uint16_t target)
// {
//     control_can_frame.data[0] = (uint8_t)(target >> 8);
//     control_can_frame.data[1] = (uint8_t)(target & 0xFF);

//     int ret = can_send(can_iface, &motor_info_frame, K_MSEC(100), NULL, NULL);
//     if (ret != 0)
//     {
//         printk("Sending failed [%d]", ret);
//         return false;
//     }
//     return true;
// }

void enable_rx_callback_filter(struct device *can_iface,uint16_t ID)
{
    can_add_rx_filter(can_iface, rx_callback_function, NULL, &target_control_filter);
}

void init_can(struct device *can_iface)
{
    __ASSERT(device_is_ready(can_iface) == true, "Cant initialize CAN device");
    __ASSERT(can_set_mode(can_iface, CAN_MODE_NORMAL) == 0, "Cant select CAN mode");
    __ASSERT(can_start(can_iface) == 0, "Cant start CAN stack");
    printk("CAN device and stack init ok\n");
}