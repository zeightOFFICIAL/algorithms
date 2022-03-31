#include "fibonacci.h"

unsigned long long int FibonacciRecursive(unsigned long long int x)
{
    if((x==1)||(x==0))
        return(x);
    return(FibonacciRecursive(x-1)+FibonacciRecursive(x-2));
}

unsigned long long int FibonacciTailRecursive(unsigned long long int x, unsigned long long int a, unsigned long long int b)
{
    if (x == 0)
        return a;
    if (x == 1)
        return b;
    return FibonacciTailRecursive(x - 1, b, a + b);
}

unsigned long long int FibonacciIterative(unsigned long long int n)
{
    unsigned long long int x = 0, y = 1, z = 0;
    for (int i = 0; i < n; i++) {
        z = x + y;
        x = y;
        y = z;
    }
    return x;
}