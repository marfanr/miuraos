#ifndef __LIBK_IO_HPP__
#define __LIBK_IO_HPP__

#include <stdint.h>

namespace miura::libk {
class IO {
public:
    static void outb(uint16_t port, uint8_t value);
    static uint8_t inb(uint16_t port);
};
} // namespace miura::libk
#endif // __LIBK_IO_HPP__