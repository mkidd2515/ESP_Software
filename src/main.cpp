#include "mbed.h"
#include "rgb_led.hpp"

int main() {
  RGB_Led led;

  for (;;) {
    led.off();
    ThisThread::sleep_for(1000ms);
    led.on(RGB_Led::RED);
    ThisThread::sleep_for(1000ms);
    led.off();
    led.on(RGB_Led::GREEN);
    ThisThread::sleep_for(1000ms);
    led.off();
    led.on(RGB_Led::BLUE);
    ThisThread::sleep_for(1000ms);
  }
}
