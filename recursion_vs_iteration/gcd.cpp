#include "gcd.h"

unsigned long long int GCDIterative(unsigned long long int x, unsigned long long int y)
{
    while(x != y) {
    if(x > y)
      x -= y;
    else
      y -= x;
    }
    return x;
}

unsigned long long int GCDRecursive(unsigned long long int x, unsigned long long int y)
{
    if (y == 0)
        return x;
    return GCDRecursive(y, x % y);
}