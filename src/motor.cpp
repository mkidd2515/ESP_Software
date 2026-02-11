#include "mbed.h"
#include "QEI.h"
#include "motor.hpp"

// FYI constructor not complete 
Motor::Motor(PinName pwmPin, int period_us, float duty, PinName chA, PinName chB) 
	:  dir(false),
	   dirOut(NC),
	   pwm(pwmPin),
	   quad(chA, chB, NC, 256)

{
	pwm.period_us(period_us);
	
}
