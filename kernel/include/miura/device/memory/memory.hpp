#ifndef __MIURA_DEVICE_MEMORY_MEMORY_HPP__
#define __MIURA_DEVICE_MEMORY_MEMORY_HPP__

#include <stdint.h>

namespace miura::device::memory {
class Memory {
public:
    typedef struct bitmap {
        uint64_t size;
        uint16_t* addr;        
    } bitmap_t;    
protected:
    inline uint64_t align_up(uint64_t addr, uint64_t align) {
        return (addr + align - 1) & ~(align - 1);
    }
    inline uint64_t align_down(uint64_t addr, uint64_t align) {
        return addr & ~(align - 1);
    }

};
} // namespace miura::device::memory

#endif // __MIURA_DEVICE_MEMORY_MEMORY_HPP__