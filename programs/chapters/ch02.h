#include "mbed.h"
#include "crazyflie.h"
#include "pin_names.h"
#include "parameters.h"


PwmOut motor4(MOTOR4);

float p = 1.0/500.0;

float control_motor(float omega){
    float PWM=1.7439e-07*(omega*omega)+3.9258e-11*omega;
    return PWM;
}


int main(){

    motor4.period(p);
    motor4=control_motor(1000.0);
    wait(10);
    motor4=0.0;

    while(true){
            
    }
}        