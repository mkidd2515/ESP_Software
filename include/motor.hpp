#ifndef MOTOR_HPP
#define MOTOR_HPP


#include "mbed.h"
#include "QEI.h"



#include <cstdint>

static constexpr int TICKER_PERIOD_US = 100;


class Motor {
protected:
	float dutyCycle; // percentage 
	int period; // in microseconds
	DigitalOut dirOut; // GPIO pin for setting direction
	PwmOut pwm; // speed control of motor
	QEI quad;  // reading the quad enc
	Ticker pulse_sampler;
	int pulse_count;
	float current_speed;
        
	void calc_speed(void) noexcept;
	
public:
	Motor(PinName dirPin, PinName pwmPin, int period_us, float duty, PinName chA, PinName chB) noexcept;
	// delete misc constructors, OBJECT SHOULD NOT BE COPIED
	Motor(const Motor&) = delete;
	Motor operator=(const Motor&) = delete;
	Motor(const Motor&&) = delete;
	Motor& operator=(const Motor&&) = delete;
        
	

	void set_dir(int newD) noexcept;
	int get_dir(void) const noexcept;

	float get_speed(void) const noexcept;
	void set_speed(float speed) noexcept; // input speed as percentage but might switch to RPM
	
};



#endif
