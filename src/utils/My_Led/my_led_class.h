#ifndef my_led_class_h
#define my_led_class_h

#include "mbed.h"
#include "pin_names.h"

class MyLedClass {
    public:
        MyLedClass();
        void blink();
    private:
        DigitalOut led;
};

#endif