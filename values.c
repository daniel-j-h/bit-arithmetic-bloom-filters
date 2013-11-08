#include <stdio.h>
#include <inttypes.h>
#include "djb2.h"

int main(void) {
  /*
    Dumping the memory at the given address:
    00000000bffffff0 : 00 00 00 a8 | 61 eb ef 58 | e6 0f 61 a2 | 46 fc 45 00 : ....a..X..a.F.E.

    And a second one:
    00000000bffffff0 : 00 00 00 a9 | 43 89 d0 1b | 40 2d c6 5e | 8e 36 45 00 : ....C...@-.^.6E.
  */
  const unsigned char ones[] = { 0xa8, 0x61, 0xeb, 0xef, 0x58, 0xe6, 0x0f, 0x61, 0xa2, 0x46, 0xfc, 0x45, 0x00 };

  uint64_t ones_h = djb2(ones);

  printf("'%s' hashes to '%#" PRIx64 "'\n", ones, ones_h);


  /*
    Dumping the memory at the given address:
    00000000bffffff0 : 00 00 00 00 | 00 00 00 00 | 00 00 38 98 | 00 3b 35 00 : ..........8..;5.

    And a second one:
    00000000bffffff0 : 00 00 00 00 | 00 00 00 00 | 00 00 a0 5b | 00 9c df 00 : ...........[....
  */
  const unsigned char fst[] = { 0x38, 0x98, 0x00 };
  const unsigned char snd[] = { 0x3b, 0x35, 0x00 };

  uint64_t fst_h = djb2(fst);
  uint64_t snd_h = djb2(snd);

  printf("'%s' hashes to '%#" PRIx64 "'\n", fst, fst_h);
  printf("'%s' hashes to '%#" PRIx64 "'\n", snd, snd_h);
}

