#include <string.h>
#include "djb2.h"

/*
 * clang -Wall -Wextra -pedantic -std=c99 djb2.c driver.c -emit-llvm -c -g -O0
 * llvm-link *.o -o driver.bc
 * llbmc --max-loop-iterations=15 --max-builtins-iterations=15 --counterexample --function-name=all_ones driver.bc
 */

/* llbmc prototypes for used features, so we don't have to include llbmc.h */
void __llbmc_assert(int);
void __llbmc_assume(int);
unsigned int __llbmc_nondef_unsigned_int(void);

void hash_collision(void) {
  /* setup fst, snd to be unequal null terminated strings of max size max */
  const size_t max = 3; /* incrementally raised to find the min size required for a collision */

  /* actual sizes */
  size_t r = __llbmc_nondef_unsigned_int();
  size_t s = __llbmc_nondef_unsigned_int();

  __llbmc_assume(0 < r && r <= max);
  __llbmc_assume(0 < s && s <= max);

  const unsigned char fst[r];
  const unsigned char snd[s];

  /* null terminated */
  __llbmc_assume(fst[r-1] == '\0');
  __llbmc_assume(snd[s-1] == '\0');

  /* fst != snd, otherwise trivial collision */
  __llbmc_assume(strncmp((const char*)fst, (const char*)snd, max) != 0);

  /* hashes */
  uint64_t hfst = djb2(fst);
  uint64_t hsnd = djb2(snd);

  /* collision */
  __llbmc_assert(hfst != hsnd);
}

void all_ones(void) {
  /* again, we're limiting the string to max size max */
  const size_t max = 13; /* incrementally raised to find the min size required for all ones */

  /* actual size */
  size_t r = __llbmc_nondef_unsigned_int();

  __llbmc_assume(0 < r && r <= max);

  const unsigned char str[r];

  /* null terminated */
  __llbmc_assume(str[r-1] == '\0');

  uint64_t hash = djb2(str);

  /* all bits one */
  __llbmc_assert((hash & ((uint64_t)-1)) != ((uint64_t)-1));
}

