#include "mbed.h"
#include "QEI.h"

// FYI constructor not complete 
Motor::Motor(PinName pwmPin, int period_us, float duty, PinName chA, PinName chB, int pulsesPerRev=256) 
	: pwm(pwmPin)
	, quad(chA, chB, NC, pulsesPerRev)
	, dir(0) 
{
	pwm.period_us(period_us);
		
}

void Motor::set_speed(float speed) {
	pwm.write(speed);
	return;	
}

int get_speed() {
	int n0, n1;
	n0 = n1 = 0;
	timer.start;
	n0 = quad.getPulses();
	wait(5 us)
}

