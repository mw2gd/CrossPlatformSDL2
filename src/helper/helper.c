#include <stdio.h>
#include <stdint.h>
uint64_t hprintf(uint64_t uint64)
{
    printf("%llu\n", uint64);
    return uint64;
}