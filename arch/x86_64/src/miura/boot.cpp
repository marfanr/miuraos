#include <libk/limine.h>
#include <miura/serial.hpp>
#include <miura/device/memory/physical_memory.hpp>
#include <miura/boot.hpp>

#define X86_64_ARCH

namespace miura::arch::x86_64 {
extern "C" void _start() {
    Serial::setup();
    limine_memmap_entry** mem_entries = memmap_request.response->entries;
    uint64_t memmap_count = memmap_request.response->entry_count;
    
    miura::device::memory::PhysicalMemory physical_memory_allocator(mem_entries, memmap_count);
    physical_memory_allocator.install();

    Serial::putc('d');
    // setup pmm
    for (;;) {}
}
} // namespace miura::arch::x86_64
