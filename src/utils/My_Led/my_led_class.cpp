#include "my_led_class.h"

MyLedClass::MyLedClass() : led(LED_RED_R)
{
}

void MyLedClass::blink()
{
    led = true;
    wait(0.5);
    led = false;
    wait(0.5);
}