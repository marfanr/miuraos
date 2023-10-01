#include <libk/string.hpp>

namespace libk
{
 void String::memset(void *dest, uint8_t val, uint64_t len)
 {
  uint8_t *dst = (uint8_t *)dest;

  for (; len != 0; len--)
   *dst++ = val;
 }   
} // namespace libk
