#include "pid.h"

/* Global Variables*/

static struct pid PID = {0};

/* Timer struct */

static struct k_timer pid_controller_tim;



static void pid_controller()
{
    int32_t rpm = get_current_rpm();
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
}

void set_pid_target_rpm(uint16_t target)
{
    PID.target = target;
}

void init_pid_controller()
{
    k_timer_init(&pid_controller_tim, pid_controller, NULL);
    k_timer_start(&pid_controller_tim, INTERVAL_PERIOD, INTERVAL_PERIOD);
}
