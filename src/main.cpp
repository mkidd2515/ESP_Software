#include "mbed.h"
#include "flash.hpp"


DigitalOut led(LED1);

int main() {
  flash(&led);
}
