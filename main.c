#include <stdio.h>
#include "bloom.h"

int main(void) {
  typedef const char* string;
  const string names[] = {"Erik", "Shark", "Laser", NULL};

  bloom* ctx = bloom_new();

  for (const string* it = names; *it != NULL; ++it)
    bloom_add(ctx, *it);

  for (const string* it = names; *it != NULL; ++it)
    printf("Contains '%s': %d\n", *it, bloom_contains(ctx, *it));

  printf("Contains 'Laser Shark': %d\n", bloom_contains(ctx, "Laser Shark"));
  printf("Contains 'Shark Erik': %d\n", bloom_contains(ctx, "Shark Erik"));

  bloom_free(ctx);
}

