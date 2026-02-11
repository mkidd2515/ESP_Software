#ifndef JOYSTICK_HPP
#define JOYSTICK_HPP

template<class InType>
class Joystick {
  private:

  public:
    template<DigitalIn>
    Joystick() noexcept {

    }

    template<InterruptIn>
    Joystick() noexcept {

    }
    Joystick(const Joystick&) = delete;
    Joystick operator=(const Joystick&) = delete;
    Joystick(const Joystick&&) = delete;
    Joystick& operator=(const Joystick&&) = delete;

};





#endif
