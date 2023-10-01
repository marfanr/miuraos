#ifndef __MIURA__ARCH__X86_64__BOOT__
#define __MIURA__ARCH__X86_64__BOOT__

#include <libk/limine.h>

namespace miura::arch::x86_64 {
inline static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST, .revision = 0};

inline static volatile struct limine_memmap_request memmap_request = {
    .id = LIMINE_MEMMAP_REQUEST, .revision = 0};
} // namespace miura::arch::x86_64

#endif // __MIURA__ARCH__X86_64__BOOT__