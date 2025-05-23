#include "can.h"

static const struct can_filter target_control_filter = {
    .flags = 0,
    .id = TARGET_CONTROL_ID,
    .mask = 0};


static const struct can_filter motor_info_filter = {
    .flags = 0,
    .id = MOTOR_INFO_ID,
    .mask = 0};


static struct can_frame control_can_frame = {
    .flags = 0,
    .id = TARGET_CONTROL_ID,
    .dlc = 2,
    .data = {0}};



void rx_callback_function(const struct device *dev, struct can_frame *frame, void *user_data)
{
    printk("\nFRAME ID: [%d]\n", frame->id);
    printk("FRAME DLC: [%d]\n", frame->dlc);
    uint16_t rpm = (frame->data[0] << 8) | (frame->data[1]);
    uint16_t target = (frame->data[2] << 8) | (frame->data[3]);
    uint16_t error = (frame->data[4] << 8) | (frame->data[5]);
    printk("RPM: [%d] - Target: [%d] - Error: [%d]\n",rpm,target,error);

}

bool send_can_control_data(struct device *can_iface, uint16_t target)
{
    control_can_frame.data[0] = (uint8_t)(target >> 8);
    control_can_frame.data[1] = (uint8_t)(target & 0xFF);

    int ret = can_send(can_iface, &control_can_frame, K_MSEC(100), NULL, NULL);
    if (ret != 0)
    {
        printk("Sending failed [%d]", ret);
        return false;
    }
    return true;
}

void enable_rx_callback_filter(struct device *can_iface,uint16_t ID)
{
    can_add_rx_filter(can_iface, rx_callback_function, NULL, &motor_info_filter);
}

void init_can(struct device *can_iface)
{
    __ASSERT(device_is_ready(can_iface) == true, "Cant initialize CAN device");
    __ASSERT(can_set_mode(can_iface, CAN_MODE_NORMAL) == 0, "Cant select CAN mode");
    __ASSERT(can_start(can_iface) == 0, "Cant start CAN stack");
    printk("CAN device and stack init ok\n");
}