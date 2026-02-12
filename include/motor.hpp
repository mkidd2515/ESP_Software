#include "mbed.h"
#include "QEI.h"

class Motor {
protected:
	float dutyCycle; // percentage 
	int period; // in microseconds
	DigitalOut dirOut; // GPIO pin for setting direction
	PwmOut pwm; // speed control of motor
	QEI quad;  // reading the quad enc
	Timer timer;
	
public:
	Motor(PinName dirPin, PinName pwmPin, int period_us, float duty, PinName chA, PinName chB);
	
	void set_dir(int newD);
	int get_dir(void);

	float get_speed(void);
	void set_speed(float speed); // input speed as percentage but might switch to RPM
};
