#include "mbed.h"
#include "QEI.h"
#include "motor.hpp"
#include <chrono>


// FYI constructor not complete 
Motor::Motor(PinName dirPin, PinName pwmPin, int period_us, PinName chA, PinName chB) noexcept : 
  	    duty_cycle(0),
	    pulse_count(0),
        period(period_us),
	    dirOut(dirPin),
	    pwm(pwmPin),
	    quad(chA, chB, NC, 256),
	    pulse_count(quad.getPulses())
{
	pwm.period_us(period_us);
	pulse_sampler.attach(callback(this, &Motor::calc_speed), std::chrono::microseconds(TICKER_PERIOD_US));
}


void Motor::calc_speed(void) noexcept {
  	int current_pulses = quad.getPulses();
  	int dPulses = current_pulses - pulse_count;
    const float pulses_per_second = 
    static_cast<float>(dPulses) / (static_cast<float>(TICKER_PERIOD_US) * 1e-6);
    current_speed = pulses_per_second / 256.0f;
    pulse_count = current_pulses;
}

void Motor::stop() noexcept {
	set_speed(0);
	return;
}

void Motor::suspend() noexcept {
	pwm.suspend();
	return;
}

void Motor::resume() noexcept {
	pwm.resume();
	return;
} 

void Motor::set_dir(int newD) noexcept{
	dirOut = static_cast<int>((newD != 0));
	return;
}

int Motor::get_dir(void) const noexcept { 
	return const_cast<DigitalOut&>(dirOut).read(); 
}

void Motor::set_speed(float speed) noexcept{
	pwm.write(speed);
	return;	
}

float Motor::get_speed(void) const noexcept{
  return current_speed;
}
