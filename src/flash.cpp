#include "flash.hpp"


void flash(DigitalOut* led){
  while (true) {
    *led = !*led;
    ThisThread::sleep_for(1000ms);
  }
}
