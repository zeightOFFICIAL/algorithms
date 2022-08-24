#include "gcd.h"

unsigned long long int GCDRecursive(unsigned long long x, unsigned long long y)
{
    if (y == 0)
        return x;
    return GCDRecursive(y, x % y);
}

unsigned long long GCDIterative(unsigned long long x, unsigned long long y)
{
    while (x != y) {
        if (x > y)
            x -= y;
        else
            y -= x;
    }
    return x;
}