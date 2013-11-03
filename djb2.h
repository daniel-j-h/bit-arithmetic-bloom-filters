#ifndef DJB2_H
#define DJB2_H

/*
 * Daniel J. Bernstein's djb2 string hashing function.
 */

#include <stdint.h>

uint64_t djb2(const unsigned char *);

#endif

