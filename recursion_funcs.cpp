#include "recursion_funcs.h"

unsigned long long int FibonacciRecursive(unsigned long long int x)
{
    if((x==1)||(x==0))
        return(x);
    return(FibonacciRecursive(x-1)+FibonacciRecursive(x-2));
}

unsigned long long int FibonacciTailRecursive(unsigned long long int n, unsigned long long int a, unsigned long long int b)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return FibonacciTailRecursive(n - 1, b, a + b);
}

unsigned long long int FactorialRecursive(unsigned long long int x)
{
    if((x==1)||(x==0))
        return 1;
    return x*FactorialRecursive(x-1);
}

unsigned long long int GCDRecursive(unsigned long long int x, unsigned long long int y)
{
    if (y == 0)
        return x;
    return GCDRecursive(y, x % y);
}