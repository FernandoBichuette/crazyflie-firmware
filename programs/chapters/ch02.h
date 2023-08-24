#include "mbed.h"
#include "crazyflie.h"
#include "pin_names.h"
#include "parameters.h"

// Define all LEDs as digital output objects

// Define all motors as PWM objects

PwmOut motor4(MOTOR4);

float p = 1.0/500.0;

int main(){

    motor4.period(p);

    while(true){
        motor4=1;
            
        }
    }        