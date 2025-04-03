#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>  
#include "serial_handler.h"

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DT_NODELABEL(led_0),gpios);


#define q_msg_size 32

K_MSGQ_DEFINE(uart_queue, q_msg_size, 10, 4);

int main(void) {

    char tx_buf[50];
    int ret;
    if(!device_is_ready(led.port)){
        return -1;
    }else{
        ret = gpio_pin_configure_dt(&led,GPIO_OUTPUT);  
        if(ret < 0){
            return -1;
        }else{
            // just to dont leave a if withou else ;p            
        }
    }
    if(serial_init()){
        printk("Serial started");
    }else{
        printk("Serial got some error lol\n");
    }

    while (1) {
        ret = gpio_pin_toggle_dt(&led);
        if(k_msgq_get(&uart_queue,&tx_buf,K_NO_WAIT) == 0){
            printk("\nMy string [%s]", tx_buf);
        };
        k_sleep(K_MSEC(50));

    }

    return 0;
}
