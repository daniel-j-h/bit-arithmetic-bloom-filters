#include "djb2.h"

uint64_t djb2(const unsigned char *str) {
  uint64_t hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash << 5) + hash) + c;

  return hash;
}

