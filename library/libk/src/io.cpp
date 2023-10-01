#include <libk/io.hpp>

namespace miura::libk {
uint8_t IO::inb(uint16_t port) {
  uint8_t ret;
  asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
  return ret;
}
void IO::outb(uint16_t port, uint8_t value) {
  asm volatile("outb %0, %1" : : "a"(value), "Nd"(port));
}
} // namespace miura::libk