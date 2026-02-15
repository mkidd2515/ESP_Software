#include "rgb_led.hpp"

RGB_Led::RGB_Led()
    : red(D5), green(D9), blue(D8), red_on(false), green_on(false),
      blue_on(false) {
  red = 1;
  green = 1;
  blue = 1;
}

void RGB_Led::on(int col) noexcept {
  if (col & 1) {
    red = 0;
    red_on = true;
  }
  if (col & 2) {
    green = 0;
    green_on = true;
  }
  if (col & 4) {
    blue = 0;
    blue_on = true;
  }
}

void RGB_Led::off(int col) noexcept {
  if (!col) {
    red = 1;
    green = 1;
    blue = 1;
    red_on = false;
    green_on = false;
    blue_on = false;
  }
  if (col & 1) {
    red = 1;
    red_on = false;
  }
  if (col & 2) {
    green = 0;
    green_on = false;
  }
  if (col & 4) {
    blue = 0;
    blue_on = false;
  }
}

void RGB_Led::toggle(void) noexcept {
  if (red_on) {
    red = 1;
    red_on = false;
  } else {
    red = 0;
    red_on = true;
  }
  if (green_on) {
    green = 1;
    green_on = false;
  } else {
    green = 0;
    green_on = true;
  }
  if (blue_on) {
    blue = 1;
    blue_on = false;
  } else {
    blue = 0;
    blue_on = true;
  }
}

bool RGB_Led::get_status_red() const noexcept { return red_on; }

bool RGB_Led::get_status_green() const noexcept { return green_on; }

bool RGB_Led::get_status_blue() const noexcept { return blue_on; }
