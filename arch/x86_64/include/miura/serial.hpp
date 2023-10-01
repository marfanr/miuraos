#ifndef __MIURA_SERIAL_HPP__
#define __MIURA_SERIAL_HPP__

namespace miura::arch::x86_64 {
class Serial {
    public:
        static bool setup();
        static void putc(const char _);
};
} // namespace miura::arch::x86_64

#endif