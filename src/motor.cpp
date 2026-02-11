#include "mbed.h"
#include "QEI.h"
#include "motor.hpp"

#include <chrono>


// FYI constructor not complete 
Motor::Motor(PinName dirPin, PinName pwmPin, int period_us, float duty, PinName chA, PinName chB) noexcept : 
  	    dutyCycle(duty),
	    period(period_us),
	    dirOut(dirPin),
	    pwm(pwmPin),
	    quad(chA, chB, NC, 256),
	    pulse_count(quad.getPulses())
{
	pwm.period_us(period_us);
	// t_prev = t_now = Kernel::get_ms_count();
	// pCntPrev = pCntNow = quad.getPulses();
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

/* Shit(TM)
 * this method doesn't work for lower speeds
 * even if we read only 1 pulse in 10 milliseconds
 * that's still 100 pulses per second
 * which is 0.390 rotations per second
 * which is in turn 0.5544 m/s
 * or a little less than HALF OUR MAX SPEED (1.17 m/s)
 * not to mention that the longer we take to sample, the more our latency is
*/ 

float Motor::get_speed(void) const noexcept{
  return current_speed;
}










	/*int n0, n1;
	n0 = n1 = 0;
	timer.start();
	n0 = quad.getPulses();
	ThisThread::sleep_for(10ms);
	n1 = quad.getPulses();
	timer.stop();
	float speed = 0;
	*/

