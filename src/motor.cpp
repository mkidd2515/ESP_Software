#include "mbed.h"
#include "QEI.h"
#include <chrono>
#include "motor.hpp"
<<<<<<< HEAD

// FYI constructor not complete 
Motor::Motor(PinName dirPin, PinName pwmPin, int period_us, float duty, PinName chA, PinName chB) 
	:  dir(false),
	   dirOut(dirPin),
	   pwm(pwmPin),
	   quad(chA, chB, NC, 256)
{
	pwm.period_us(period_us);
}

void Motor::set_speed(float speed) {
	pwm.write(speed);
	return;	
}

int Motor::get_speed() {
	int n0, n1;
	n0 = n1 = 0;
	timer.start;
	n0 = quad.getPulses();
	wait(10ms);
	n1 = quad.getPulses();
	timer.stop;
}

