#include "mbed.h"
#include "motor.hpp"
#include "rgb_led.hpp"
#include "pins.hpp"




int main() {
    Motor motor1(M1_DIROUT, M1_PWMOUT, MTR_PRD_US, M1_CHA, M1_CHB);
    Motor motor2(M2_DIROUT, M2_PWMOUT, MTR_PRD_US, M2_CHA, M2_CHB); 
    
    // PWM speed test 
    // MAKE SURE THE BUGGY IS UPSIDE DOWN OR OTHERWISE SAFE TO MOVE ABOUT
    // ELSE IT MIGHT RUN OFF AND GET DAMAGED 
    for (float i = 1; i <= 100.0f; i += 1.0f) {
         motor1.set_speed(1.0f/i));
        
         if(0 == motor1.get_speed()) { 
             printf("%f\% Duty Cycle Insufficient\n");
         } else
             ThisThread::sleep_for(1s);
         }
    }
    motor1.stop();

    for (float i = 1; i <= 100.0f; i += 1.0f) {
        motor2.set_speed(1.0.f / i);
         if(motor2.get_speed() == 0) { 
             printf("%i\% Duty Cycle Insufficient\n");
         } else
             ThisThread::sleep_for(1s);
    }
    motor2.stop();

    do {} while(1);
}
