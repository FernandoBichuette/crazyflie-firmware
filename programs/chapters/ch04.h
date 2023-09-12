#include "mbed.h"
#include "crazyflie.h"
#include "pin_names.h"
#include "parameters.h"

PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

float p = 1.0/500.0;


float control_motor(float omega){
    float PWM=1.7439e-07*(omega*omega)+3.9258e-11*omega;
    return PWM;
}

int main(){

    motor1.period(p);
    motor2.period(p);
    motor3.period(p);
    motor4.period(p);
    wait(2);
    motor1=control_motor(1000.0);
    motor2=control_motor(2000.0);
    motor3=control_motor(1000.0);
    motor4=control_motor(2000.0);
    wait(2);
    motor1=0.0;
    motor2=0.0;
    motor3=0.0;
    motor4=0.0;

    while(true){
            
    }
}        