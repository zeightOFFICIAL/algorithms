#include "totalsum.h"

unsigned long long int SumRecursive(unsigned long long int x, unsigned long long int y) {
    if (y==x)
        return y;
    return y+SumRecursive(x,y-1); 
}

unsigned long long int SumIterative(unsigned long long int x, unsigned long long int y) {
    unsigned long long int result = 0;
    for (unsigned long long int k = x; k <= y; k++)
        result = result + k;
    return result;
}