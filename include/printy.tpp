
// CURRENTLY NO SUPPORT FOR > 32 BIT INTS
template<typename T>
typename std::enable_if<
  std::is_arithmetic<T>::value && 
  std::is_integral<T>::value,
  Printy&
>::type
Printy::operator<<(const T& buff) {
  if (Base::DEC == base)
    serial_printf("%d", static_cast<int>(buff));
  if (Base::HEX == base) 
    serial_printf("%x", static_cast<int>(buff));
  if (Base::BIN == base) 
    printbin<T>(buff);
  return *this;
}


template<typename T>
typename std::enable_if<
  std::is_floating_point<T>::value, 
  Printy&
>::type
Printy::operator<<(const T& buff) noexcept {
  double val = static_cast<double>(buff);
  serial_printf("%.*f", precision, val);
  return *this;
}


template<typename T>
typename std::enable_if<
  std::is_convertible<T, std::string>::value,
  Printy&
>::type
Printy::operator<<(const T& buff) noexcept {
  std::string local(buff);
  serial_out.write(local.c_str(), local.size() * sizeof(char) + 1);
  return *this;
}



template<typename T>
void Printy::printbin(T num) noexcept {
  using U = typename std::make_unsigned<T>::type;

  U u = static_cast<U>(num);
  U msb = U(1) << (sizeof(T) * 8 - 1);

  while (msb > 0) {
    serial_printf((u&msb) ? "1" : "0", 1);
    msb >>= 1;
  }
}


