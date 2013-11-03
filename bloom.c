#ifdef BLOOM_DEBUG
  #include <inttypes.h>
  #include <stdio.h>
#endif

#include <stdlib.h>
#include "bloom.h"
#include "djb2.h"

bloom* bloom_new(void) {
  bloom* out = malloc(sizeof(bloom));
  *out = (bloom){0};
  return out;
}

bloom* bloom_copy(bloom const *in) {
  bloom* out = malloc(sizeof(bloom));
  *out = *in;
  return out;
}

void bloom_free(bloom *in) {
  free(in);
}

void bloom_add(bloom* in, char const *key) {
  uint64_t hash = djb2((unsigned char const*)key);

#ifdef BLOOM_DEBUG
  printf("'%s' hashes to '%#" PRIx64 "'\n", key, hash);
#endif

  in->bits |= hash;
}

bool bloom_contains(bloom const* in, char const *key) {
  uint64_t hash = djb2((unsigned char const*)key);

#ifdef BLOOM_DEBUG
  printf("'%s' hashes to '%#" PRIx64 "'\n", key, hash);
#endif

  return (in->bits & hash) == hash;
}

bloom* bloom_union(bloom const *lhs, bloom const *rhs) {
  bloom* out = malloc(sizeof(bloom));
  *out = (bloom){.bits = lhs->bits | rhs->bits};
  return out;
}

bloom* bloom_intersect(bloom const *lhs, bloom const *rhs) {
  bloom* out = malloc(sizeof(bloom));
  *out = (bloom){.bits = lhs->bits & rhs->bits};
  return out;
}

