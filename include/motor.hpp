#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "QEI.h"
#include "mbed.h"
#include <cstdint>

// might be too fast to read
static constexpr int TICKER_PERIOD_US = 100;

static constexpr int MTR_PRD_US = 10;

static_assert((TICKER_PERIOD_US != 0),
              "Ticker period must be non 0 COMPILATION ERROR");

class Motor {
protected:
  float duty_cycle; // percentage
  int pulse_count;
  int period; // in microseconds
  float current_speed;
  DigitalOut dirOut; // GPIO pin for setting direction
  PwmOut pwm;        // speed control of motor
  QEI quad;          // reading the quad enc
  Ticker pulse_sampler;

  void calc_speed(void) noexcept;

public:
  Motor(PinName dirPin, PinName pwmPin, int period_us, PinName chA,
        PinName chB) noexcept;
  // delete misc constructors, OBJECT SHOULD NOT BE COPIED
  Motor(const Motor &) = delete;
  Motor operator=(const Motor &) = delete;
  Motor(const Motor &&) = delete;
  Motor &operator=(const Motor &&) = delete;

  void start() noexcept;
  void suspend() noexcept;
  void resume() noexcept;
  void stop() noexcept;

  void set_dir(int newD) noexcept;
  int get_dir(void) const noexcept;

  float get_speed(void) const noexcept;
  void set_speed(float speed) noexcept; // input speed as percentage but might
                                        // switch to RPM
};

#endif
