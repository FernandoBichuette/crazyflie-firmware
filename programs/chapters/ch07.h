#include "mbed.h"
#include "crazyflie.h"
#include "pin_names.h"
#include "parameters.h"

PwmOut motor_1(MOTOR1);
PwmOut motor_2(MOTOR2);
PwmOut motor_3(MOTOR3);
PwmOut motor_4(MOTOR4);

float omega_1;
float omega_2;
float omega_3;
float omega_4;

float control_motor(float omega) {
    float PWM=1.7439e-07*(omega*omega)+3.9258e-11*omega;
    return PWM;
}

float positive_or_zero(float x) {
    return x > 0 ? x : 0;
}

void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi) {
    omega_1 = sqrt(positive_or_zero(
        ((1 / (4 * kl)) * f_t) + 
        (- (1 / (4 * kl * l)) * tau_phi) + 
        (- (1 / (4 * kl * l)) * tau_theta) + 
        (- (1 / (4 * kd)) * tau_psi)
    ));

    omega_2 = sqrt(positive_or_zero(  
        ((1 / (4 * kl)) * f_t) + 
        (- (1 / (4 * kl * l)) * tau_phi) + 
        ((1 / (4 * kl * l)) * tau_theta) + 
        ((1 / (4 * kd)) * tau_psi)
    ));   

    omega_3 = sqrt(positive_or_zero( 
        ((1 / (4 * kl)) * f_t) + 
        ((1 / (4 * kl * l)) * tau_phi) + 
        ((1 / (4 * kl * l)) * tau_theta) + 
        (- (1 / (4 * kd)) * tau_psi)
    )); 

    omega_4 = sqrt(positive_or_zero(
        ((1 / (4 * kl)) * f_t) + 
        ((1 / (4 * kl * l)) * tau_phi) + 
        (- (1 / (4 * kl * l)) * tau_theta) + 
        ((1 / (4 * kd)) * tau_psi)
    ));   
}

void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi) {
    mixer(f_t, tau_phi, tau_theta, tau_psi);
    motor_1 = control_motor(omega_1);
    motor_2 = control_motor(omega_2);
    motor_3 = control_motor(omega_3);
    motor_4 = control_motor(omega_4);
}

int main() {
    motor_1.period(1.0/500.0);
    motor_2.period(1.0/500.0);
    motor_3.period(1.0/500.0);
    motor_4.period(1.0/500.0);

    // actuate(0.5*m*g, 0, 0, 0);
    wait(2);
    actuate(0, 0, 0, -0.001);
    wait(5);
    actuate(0, 0, 0, 0);
    while (true) { }
}

