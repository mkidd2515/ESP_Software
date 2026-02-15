#ifndef PRINTY_HPP
#define PRINTY_HPP

#include "mbed.h"


#include <string>
#include <memory>
#include <sstream>
#include <cstdarg>

static constexpr int BAUD_RATE = 115200;


enum class Base {
  HEX, DEC, BIN
};

struct __precisionmanip {
  int val;
};

class Printy {
  private:
    BufferedSerial serial_out;
    template<typename T>
    void printbin(T num) noexcept;
    void serial_printf(const char* fmt, ...);
  public:
    int precision = 0;
    Base base;
    Printy() noexcept;
    Printy(const Printy&) noexcept = delete;
    Printy operator=(const Printy&) noexcept = delete;
    Printy(const Printy&&) noexcept = delete;
    Printy& operator=(const Printy&&) noexcept = delete;

    template<typename T>
    typename std::enable_if<
      std::is_arithmetic<T>::value && 
      std::is_integral<T>::value,
      Printy&
    >::type operator<<(const T& buff) noexcept;

    template<typename T>
    typename std::enable_if<
      std::is_convertible<T, std::string>::value,
      Printy&
    >::type
    operator<<(const T& buff) noexcept;
    

    template<typename T>
    typename std::enable_if<
      std::is_floating_point<T>::value, 
      Printy&
    >::type operator<<(const T& buff) noexcept;
   

    
    Printy& operator<<(Printy& (*fnmanip)(Printy&)) noexcept;
    Printy& operator<<(__precisionmanip pm) noexcept;

    static __precisionmanip setprecision(int n) noexcept;
    static Printy& hex(Printy& p) noexcept;
    static Printy& dec(Printy& p) noexcept;
    static Printy& bin(Printy& p) noexcept;
};



#include "printy.tpp"


#endif
