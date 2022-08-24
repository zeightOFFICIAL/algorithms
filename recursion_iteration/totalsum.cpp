#include "totalsum.h"

unsigned long long SumRecursive(unsigned long long x, unsigned long long y) {
    if (y == x)
        return y;
    return y + SumRecursive(x,y-1); 
}

unsigned long long SumIterative(unsigned long long x, unsigned long long y) {
    unsigned long long result = 0;
    for (unsigned long long k = x; k <= y; k++)
        result = result + k;
    return result;
}