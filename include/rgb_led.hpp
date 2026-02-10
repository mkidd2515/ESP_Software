#ifndef RGB_LED_HPP
#define RGB_LED_HPP
#include "mbed.h"
#include <memory>





class RGB_Led {
  private:
    DigitalOut red, green, blue;
    bool red_on, green_on, blue_on;

  public:
    enum Colors {
      RED = 1, GREEN = 2, BLUE = 4
    };
    RGB_Led() noexcept;
    RGB_Led(const RGB_Led&) = delete;
    RGB_Led operator=(const RGB_Led&) = delete;
    RGB_Led(const RGB_Led&&) = delete;
    RGB_Led& operator=(const RGB_Led&&) = delete;
    

    void on(int col) noexcept;
    void off(int col = 0) noexcept;
    void toggle(void) noexcept;
    
    bool get_status_red() const noexcept;
    bool get_status_green() const noexcept;
    bool get_status_blue() const noexcept;

};





#endif
