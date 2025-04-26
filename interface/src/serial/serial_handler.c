#include "serial_handler.h"


static struct buffer rx_buffer;

static void uart_cb_function(const struct device *uart_dev, void *user_data){
    
    
    if(!uart_irq_update(uart_dev)){
        return;
    }
    if(!uart_irq_rx_ready(uart_dev)){
        return;
    }else{
        uint8_t c;
        while(uart_fifo_read(uart_dev,&c,1) == 1){
            if ((c == '\n' || c == '\r') && rx_buffer.pos > 0){
                rx_buffer.buffer[rx_buffer.pos] = '\0';
                k_msgq_put(&uart_queue,&rx_buffer.buffer,K_NO_WAIT);
                rx_buffer.pos = 0;
            }else if(rx_buffer.pos < (sizeof(rx_buffer.buffer) -1)){
                rx_buffer.buffer[rx_buffer.pos++] = c;
            }else{
                // MISRA
            }
        }
    }

}


bool serial_init(struct device * uart_dev){
    printk("Check if device is ready");
    __ASSERT(device_is_ready(uart_dev) == true, "UART NOT READY");
   

    int ret = uart_irq_callback_user_data_set(uart_dev,uart_cb_function,NULL);
    if (ret < 0) {
		if (ret == -ENOTSUP) {
			printk("Interrupt-driven UART API support not enabled\n");
		} else if (ret == -ENOSYS) {
			printk("UART device does not support interrupt-driven API\n");
		} else {
			printk("Error setting UART callback: %d\n", ret);
		}
		return false;
	}else{
        printk("Callback seted\n");
    }
    uart_irq_rx_enable(uart_dev);

    return true;
}