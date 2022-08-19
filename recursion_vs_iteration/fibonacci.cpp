#include "fibonacci.h"

unsigned long long FibonacciRecursive(unsigned long long x)
{
    if ((x == 1) || (x == 0))
        return(x);
    return(FibonacciRecursive(x-1)+FibonacciRecursive(x-2));
}

unsigned long long FibonacciTailRecursive(unsigned long long x, unsigned long long a, unsigned long long b)
{
    if (x == 0)
        return a;
    if (x == 1)
        return b;
    return FibonacciTailRecursive(x - 1, b, a + b);
}

unsigned long long FibonacciIterative(unsigned int n)
{
    unsigned long long x = 0, y = 1, z = 0;
    for (int i = 0; i < n; i++) {
        z = x + y;
        x = y;
        y = z;
    }
    return x;
}