#include <libk/io.hpp>
#include <miura/serial.hpp>

namespace miura::arch::x86_64 {
using libk::IO;
bool Serial::setup() {
    IO::outb(0x3f8 + 1, 0x00);
	IO::outb(0x3f8 + 3, 0x80);
	IO::outb(0x3f8 + 0, 0x03);
	IO::outb(0x3f8 + 1, 0x00);
	IO::outb(0x3f8 + 3, 0x03);
	IO::outb(0x3f8 + 2, 0xC7);
	IO::outb(0x3f8 + 4, 0x0B);
}
void Serial::putc(const char _) {
	IO::outb(0x3f8, _);
}
} // namespace miura::arch::x86_64