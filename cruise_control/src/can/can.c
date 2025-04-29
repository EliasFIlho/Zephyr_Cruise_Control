#include "can.h"

// CAN FILTER TO RECEIVE PROCESS
static const struct can_filter target_control_filter = {
    .flags = 0,
    .id = TARGET_CONTROL_ID,
    .mask = 0};

// CAN FRAME TO TRANSMITTER PROCESS
static struct can_frame motor_info_frame = {
    .flags = 0,
    .id = MOTOR_INFO_ID,
    .dlc = 6,
    .data = {0}};

void rx_callback_function(const struct device *dev, struct can_frame *frame, void *user_data)
{
    uint16_t target = (frame->data[0] << 8) | (frame->data[1]);
    k_msgq_put(&can_rx_queue, &target, K_NO_WAIT);
}

bool send_motor_info_frame(struct device *can_iface, struct control_info *motor_info)
{
    motor_info_frame.data[0] = (motor_info->rpm >> 8);
    motor_info_frame.data[1] = (motor_info->rpm & 0xFF);

    motor_info_frame.data[2] = (motor_info->target >> 8);
    motor_info_frame.data[3] = (motor_info->target & 0xFF);

    motor_info_frame.data[4] = (motor_info->error_abs >> 8);
    motor_info_frame.data[5] = (motor_info->error_abs & 0xFF);

    int ret = can_send(can_iface, &motor_info_frame, K_MSEC(10), NULL, NULL);
    if (ret != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int enable_rx_callback_filter(struct device *can_iface)
{
    return can_add_rx_filter(can_iface, rx_callback_function, NULL, &target_control_filter);
}

void init_can(struct device *can_iface)
{
    __ASSERT(device_is_ready(can_iface) == true, "Cant initialize CAN device");
    __ASSERT(can_set_mode(can_iface, CAN_MODE_NORMAL) == 0, "Cant select CAN mode");
    __ASSERT(enable_rx_callback_filter(can_iface) >= 0, "Error to set rx callback filter");
    __ASSERT(can_start(can_iface) == 0, "Cant start CAN stack");
    printk("CAN device and stack init ok\n");
}