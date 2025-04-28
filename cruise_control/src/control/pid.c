#include "pid.h"

/* Global Variables*/
static struct pid PID = {0};

/*RPM VALUE SETED BY CONTROLLER*/
static volatile _Atomic int32_t rpm = 0;


K_THREAD_STACK_DEFINE(PID_STACK_AREA, PID_THREAD_STACK);
struct k_thread pid_thread;



/*PID Thread Function*/
//TODO: Use can_tx_queue to send a control_info_frame
static void pid_controller()
{
    while (1)
    {

        //rpm = get_current_rpm();
        PID.error = PID.target - rpm;
        if (PID.error == 0 && PID.target == 0)
        {
            PID.pid_output = 0.0;
            PID.integral = 0.0;
        }
        else
        {
            if (PID.target == 0)
            {
                PID.integral = 0;
            }
            else if (abs(PID.error) > ERROR_TOLERANCE && (!PID.saturation))
            {
                PID.integral += (PID.error * INTERVAL_PERIOD_FP);
            }
            else
            {
                // Stop increment integral
            }
        }

        PID.proportional = (KP * (float)PID.error);
        PID.derivative = (PID.error - PID.prev_error) / INTERVAL_PERIOD_FP;
        PID.pid_output = ((PID.proportional) + (KI * PID.integral) + (KD * PID.derivative));

        if (PID.pid_output >= MAX_OUTPUT)
        {

            PID.pid_output = MAX_OUTPUT;
            PID.saturation = true;
        }
        else if (PID.pid_output <= MIN_OUTPUT)
        {
            PID.pid_output = MIN_OUTPUT;
        }
        else
        {
            PID.saturation = false;
        }

        set_pwm_duty_period((uint32_t)PID.pid_output);
        PID.prev_error = PID.error;
        printk("RPM VALUE | %d | Target | %d | | Error | %d | PID | %f | Integral Value | %f |\n", rpm, PID.target, PID.error, PID.pid_output, PID.integral);
        // printk("%d,%d,%d\n", rpm, PID.target, PID.error);
        k_msleep(PID_THREAD_PERIOD_MS);
    }
}

void set_pid_target_rpm(uint16_t target)
{
    PID.target = target;
}

void set_pid_current_rpm(int32_t current_rpm){
    rpm = current_rpm;
}

k_tid_t init_pid_controller()
{
    return k_thread_create(&pid_thread, PID_STACK_AREA,
                           K_THREAD_STACK_SIZEOF(PID_STACK_AREA),
                           pid_controller,
                           NULL,
                           NULL,
                           NULL,
                           PID_THREAD_PRIORITY, PID_THREAD_OPTIONS, K_NO_WAIT);
}
