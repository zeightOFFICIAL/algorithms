#include "factorial.h"

unsigned long long FactorialRecursive(unsigned long long x)
{
    if ((x == 1) || (x == 0))
        return 1;
    return x * FactorialRecursive(x-1);
}

unsigned long long FactorialIterative(unsigned int x)
{
    unsigned long long int fact = 1 , i;
    for(i = 1; i <= x; i++)
        fact = fact * i;
    return fact;
}
