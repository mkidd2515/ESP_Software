#include "mbed.h"
#include "QEI.h"

class Motor {
protected:
	bool dir; // motor turning direction
	float dutyCycle; // percentage 
	int period; // in microseconds
	DigitalOut dirOut; // GPIO pin for setting direction
	PwmOut pwm; // speed control of motor
	QEI quad;  // reading the quad enc
	
public:
	Motor(PinName pin, int period_us, float duty, PinName chA, PinName chB);
	
	int get_speed();
	
	void set_speed(float speed); // input speed as percentage but might switch to RPM
	

};
