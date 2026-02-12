#include "mbed.h"
#include "QEI.h"
#include "motor.hpp"

// FYI constructor not complete 
Motor::Motor(PinName dirPin, PinName pwmPin, int period_us, float duty, PinName chA, PinName chB) 
	:	dutyCycle(duty),
	    period(period_us),
	    dirOut(dirPin),
	    pwm(pwmPin),
	    quad(chA, chB, NC, 256)
{
	pwm.period_us(period_us);
}

void Motor::set_dir(int newD) {
	dirOut = newD & 0x1;
	return;
}

int Motor::get_dir(void) { 
	return dirOut; 
}

void Motor::set_speed(float speed) {
	pwm.write(speed);
	return;	
}

/* Shit(TM)
 * this method doesn't work for lower speeds
 * even if we read only 1 pulse in 10 milliseconds
 * that's still 100 pulses per second
 * which is 0.390 rotations per second
 * which is in turn 0.5544 m/s
 * or a little less than HALF OUR MAX SPEED (1.17 m/s)
 * not to mention that the longer we take to sample, the more our latency is
*/ 
float Motor::get_speed(void) {
	/*int n0, n1;
	n0 = n1 = 0;
	timer.start();
	n0 = quad.getPulses();
	ThisThread::sleep_for(10ms);
	n1 = quad.getPulses();
	timer.stop();
	float speed = 0;
	*/
	return 0.0f;	
}

