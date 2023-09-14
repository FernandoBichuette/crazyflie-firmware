#include "mbed.h"
#include "my_led_class.h"

MyLedClass my_led;

int main() {
    while (true) {
        my_led.blink();
    }
}