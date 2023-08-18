#include "mbed.h"
#include "crazyflie.h"
#include "pin_names.h"
#include "parameters.h"

// Define all LEDs as digital output objects

// Define all motors as PWM objects
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

DigitalOut blue_led_e(LED_BLUE_L);
DigitalOut red_led_d(LED_RED_R);
DigitalOut red_led_e(LED_BLUE_L);
DigitalOut green_led_d(LED_GREEN_R);
DigitalOut green_led_e(LED_GREEN_L);

// Main program
int main()
{
    blue_led_e=true;
    green_led_d=true;
    green_led_e=true;
    red_led_d=true;
    red_led_e=true;
    int i=0;
    int t=0;
    float f=10.0;
    float freq=0.0;
    motor1=0;
    motor2=0;
    motor3=0;
    motor4=0;
    // Blink blue LED indicating inicialization (5 seconds)
    
    // Turn on red LEDs indicating motors are armed
    
    // Test all motors with different frequencies (to make different noises)
    
    // Turn off red LEDs indicating motors are disarmed
    
    // Blink green LEDs indicating end of program
    while(f<500){
        for (;i < 5;i++) {
            blue_led_e =!blue_led_e;
            wait(2);
        }
        if (i==5){
            blue_led_e=true;
            red_led_e=false;
            red_led_d=false;
            motor1=0;
            motor2=0;
            motor3=0;
            motor4=0;
            for(;f<500;f++){
                freq=1/f;
                
                motor1.period(freq);
                motor1=0.5;
                wait_ms(75);

                motor2.period(freq);
                motor2=0.5;
                wait_ms(75);

                motor3.period(freq);
                motor3=0.5;
                wait_ms(75);
                
                motor4.period(freq);
                motor4=0.5;
                wait_ms(75);
            }
        }
    }        
    while(f>=500){
        red_led_e=true;
        red_led_d=true;
        for(;t<5;t++){
            green_led_d=!green_led_d;
            green_led_d=!green_led_d;
            wait(1);
            
        }
        
    }
            
        

}
