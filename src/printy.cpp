#include "printy.hpp"


Printy::Printy() noexcept : serial_out(USBTX, USBRX, BAUD_RATE), precision(-1), base(Base::DEC) {}



Printy& Printy::operator<<(Printy& (*fnmanip)(Printy&)) noexcept {
  return fnmanip(*this);
}


Printy& Printy::operator<<(__precisionmanip pm) noexcept {
  precision = pm.val;
  return *this;
}


void Printy::serial_printf(const char* fmt, ...) {
  char buf[128];

  va_list args;
  va_start(args, fmt);

  int n = vsnprintf(buf, sizeof(buf), fmt, args);
  va_end(args);
  if (0 < n) {
    serial_out.write(buf, n);
  }
}

Printy& Printy::hex(Printy& p) noexcept {
  p.base = Base::HEX;
  return p;
}
Printy& Printy::dec(Printy& p) noexcept {
  p.base = Base::DEC;
  return p;
}
Printy& Printy::bin(Printy& p) noexcept {
  p.base = Base::BIN;
  return p;
}


__precisionmanip Printy::setprecision(int n) noexcept {
  return __precisionmanip{n};
}



