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
    k_msgq_put(&can_rx_queue,&target,K_NO_WAIT);
}





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