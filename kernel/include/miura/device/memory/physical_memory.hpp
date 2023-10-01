#ifndef __MIURA_DEVICE_MEMORY_PHYSICAL_MEMORY_HPP__
#define __MIURA_DEVICE_MEMORY_PHYSICAL_MEMORY_HPP__

#include <libk/limine.h>
#include <miura/device/memory/memory.hpp>
#include <stdint.h>

namespace miura::device::memory {
#define BIT_SET(a, n) (a[n / 16] |= (1 << (n % 16)))
#define BIT_CLEAR(a, n) (a[n / 16] &= ~(1 << (n % 16)))
#define BIT_TEST(a, n) (a[n / 16] & (1 << (n % 16)))
class PhysicalMemory : public Memory {
public:
  PhysicalMemory(limine_memmap_entry **mem_entries, uint64_t memmap_count);
  void install();
  static PhysicalMemory *get_instance();
  void *allocate(uint64_t size);
  void free(void *addr);
  void *calloc(uint64_t size);

protected:
private:
  bitmap_t bitmap_;
  limine_memmap_entry **mem_entries_;
  uint64_t memmap_count_;
};
} // namespace miura::device::memory

#endif // __MIURA_DEVICE_MEMORY_PHYSICAL_MEMORY_HPP__