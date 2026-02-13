#include "mbed.h"
#include "motor.hpp"
#include "rgb_led.hpp"




static constexpr PinName M1_CHA    = NC;
static constexpr PinName M1_CHB    = NC;
static constexpr PinName M1_DIROUT = NC;
static constexpr PinName M1_PWMOUT = NC;

static constexpr PinName M2_CHA    = NC;
static constexpr PinName M2_CHB    = NC;
static constexpr PinName M2_DIROUT = NC;
static constexpr PinName M2_PWMOUT = NC;

static constexpr int MTR_PRD_US = 10; 


int main() {
    Motor motor1(M1_DIROUT, M1_PWMOUT, MTR_PRD_US, M1_CHA, M1_CHB);
    Motor motor2(M2_DIROUT, M2_PWMOUT, MTR_PRD_US, M2_CHA, M2_CHB); 

    return 0;
}
