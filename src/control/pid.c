#include "pid.h"

/* Global Variables*/
static int32_t error = 0;
static double prev_error = 0.0;
static int32_t target_value = 0;
static double integral_value = 0.0;
static double derivative_value = 0.0;
static double PID = 0;
//static uint32_t output = 0;



/* Timer struct */

static struct k_timer pid_controller_tim;

static void pid_controller()
{
    int32_t rpm = get_current_rpm();
    error = target_value - rpm;
    if(error == 0 && target_value == 0){
        PID = 0.0;
        integral_value = 0.0;
    }else{
        if(target_value == 0){
            integral_value = 0;    
        }else{
            integral_value += (error * INTERVAL_PERIOD_FP);
        }

        derivative_value = (error - prev_error) / INTERVAL_PERIOD_FP;
        PID = (KP * error) + (KI * integral_value) + (KD * derivative_value);
        if(PID >= MAX_OUTPUT){
            PID = MAX_OUTPUT;
            // This windup clamp may not be the better way to do that but for now it will need to work
            integral_value = INTEGRAL_WINDUP_LIMIT;
        }else if(PID <= MIN_OUTPUT){
            PID = MIN_OUTPUT;
        }else{
            
        }

    }
    set_pwm_duty_period((uint32_t)PID);
    prev_error = error;

    //printk("RPM VALUE | %d | Target | %d | | Error | %d | PID | %f | Integral Value | %f |\n",rpm, target_value ,error, PID,integral_value);
    printk("%d,%d,%d\n",rpm, target_value ,error);
}

void set_pid_target_rpm(int16_t target)
{
    //printk("PID set target check");
    target_value = target;
}

void start_pid_controller()
{
    printk("PID start timer check");
    k_timer_init(&pid_controller_tim, pid_controller, NULL);
    k_timer_start(&pid_controller_tim, INTERVAL_PERIOD, INTERVAL_PERIOD);
}
