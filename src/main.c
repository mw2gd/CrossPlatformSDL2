#include "helper.h"
#include <stdint.h>

int main()
{
    uint64_t uint64 = 0xFFFFFFFF;
    return hprintf(uint64);
}