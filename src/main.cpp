#include "mbed.h"
#include "motor.hpp"
#include "rgb_led.hpp"


#typedef (static constexpr PinName) PIN;


PIN M1_CHA     NC;
PIN M1_CHB     NC;
PIN M1_DIROUT  NC;
PIN M1_PWMOUT  NC;

PIN M2_CHA     NC;
PIN M2_CHB     NC;
PIN M2_DIROUT  NC;
PIN M2_PWMOUT  NC;

static constexpr int MTR_PRD_US 10; // microseconds


int main() {
    Motor motor1(M1_DIROUT, M1_PWMOUT, MTR_PRD_US, 0, M1_CHA, M1_CHB);
    Motor motor2(M2_DIROUT, M2_PWMOUT, MTR_PRD_US, 0, M2_CHA, M2_CHB); 

    return 0;
}
