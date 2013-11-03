#ifndef BLOOM_H
#define BLOOM_H

/*
 * Simple bloom filter with a fixed size of bits and one hashing function.
 * For more details see e.g. https://en.wikipedia.org/wiki/Bloom_filter
 *
 * Nov. 4th, 2013
 * Daniel J. H. <daniel+osdev@trvx.org>
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct bloom {
  uint64_t bits;
} bloom;

bloom* bloom_new(void);
bloom* bloom_copy(bloom const *);
void bloom_free(bloom*);

void bloom_add(bloom*, char const *);
bool bloom_contains(bloom const *, char const *);

bloom* bloom_union(bloom const *, bloom const *);
bloom* bloom_intersect(bloom const *, bloom const *);

#endif

