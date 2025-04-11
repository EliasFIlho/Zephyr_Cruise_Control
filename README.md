# Zephyr - Cruise Control


# Main Goal

1. Learn how to use Zephyr (The better way to do that is coding and failing).
2. Learn more about control concepts such as configure samples rates and PID tuning

# The Idea

The Project idea is to create a velocity control system such in vehicles cruise control system.

## Cruise control

If you're dring at 60km/h you can send this velocity value to the cruise control system and the control algorithm
will incress and decress the car velocity in order to keep the velocity at the seted target.

## Project specifications

The project will be based in Zephyr RTOS, the system will receive a target value from UART and send this value to a PID routine that will try to reach and keep the value.

The plant that PID algorithm control is one DC motor and the feedback data comes from a quadrature encoder.

Since the control is'nt in moviment the measurement unit will be RPM (Revolutions per minute).

# Road Map

This project was planned to have three versions

1. Receiving data from UART and control algorithm in the same Microcontroller
2. Receiving data from UART in one microcontroller then send the data to another through CAN bus the next microcontroller will be responsable to run the PID algorithm.
3. Receiving data from a mechanic device similar to a cars pedal in one microcontroller then send the data to another through CAN bus the next microcontroller will be responsable to run the PID algorithm.