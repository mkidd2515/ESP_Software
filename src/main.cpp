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
    
    // PWM speed test 
    // MAKE SURE THE BUGGY IS UPSIDE DOWN OR OTHERWISE SAFE TO MOVE ABOUT
    // ELSE IT MIGHT RUN OFF AND GET DAMAGED 
    for (int i = 0; i <= 100; i++) {
         motor1.set_speed((float)(1/(float)i));
        
         if(motor1.get_speed() == 0) { 
             printf("%i\% Duty Cycle Insufficient\n");
         } else
             ThisThread::sleep_for(1s);
    }
    motor1.stop();

    for (int i = 0; i <= 100; i++) {
        motor2.set_speed((float)(1/(float)i));
         if(motor2.get_speed() == 0) { 
             printf("%i\% Duty Cycle Insufficient\n");
         } else
             ThisThread::sleep_for(1s);
    }
    motor2.stop();

    while (1);
}
