#include <libk/string.hpp>
#include <miura/device/memory/physical_memory.hpp>

namespace miura::device::memory {
PhysicalMemory::PhysicalMemory(limine_memmap_entry **mem_entries,
                               uint64_t memmap_count)
    : mem_entries_(mem_entries), memmap_count_(memmap_count) {
}
void PhysicalMemory::install() {
  uint64_t memory_size = 0;
  for (uint64_t i = 0; i < memmap_count_; i++) {
    limine_memmap_entry *entry = mem_entries_[i];
    uint64_t length = entry->length;
    memory_size += length;
  }
  bitmap_.size = align_down(align_up(memory_size, 4096) / 4096 / 16, 4096);

  for (uint64_t i = 0; i < memmap_count_; i++) {
    limine_memmap_entry *entry = mem_entries_[i];
    if (entry->type == LIMINE_MEMMAP_USABLE) {
      uint64_t size = entry->base + entry->length;
      if (size > bitmap_.size) {
        bitmap_.addr = (uint16_t *)entry->base;
        entry->base += bitmap_.size;
        entry->length -= bitmap_.size;
        break;
      }
    }
  }

  libk::String::memset(bitmap_.addr, 0xFFFF, bitmap_.size);

}
} // namespace miura::device::memory