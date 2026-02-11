#include "mbed.h"
#include "QEI.h"

// FYI constructor not complete 
Motor::Motor(PinName pwmPin, int period_us, float duty, PinName chA, PinName chB) 
	: pwm(pwmPin)
	, quad(chA, chB, NULL, 256)
	, dir(0) 
{
	pwm.period_us(period_us);
	
}
