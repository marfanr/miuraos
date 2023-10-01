#ifndef __MIURA__LIBK__STRING__
#define __MIURA__LIBK__STRING__

#include <stdint.h>

namespace libk {
class String {
public:
  static void memset(void *dest, uint8_t val, uint64_t len);
  static void memcpy(void *dest, const void *src, uint64_t len);
  static int strcmp(const char *str1, const char *str2);
  static char *strcpy(char *dest, const char *src);
};
} // namespace libk

#endif // __MIURA__LIBK__STRING__