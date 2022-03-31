#include "factorial.h"

unsigned long long int FactorialRecursive(unsigned long long int x)
{
    if((x==1)||(x==0))
        return 1;
    return x*FactorialRecursive(x-1);
}
unsigned long long int FactorialIterative(unsigned long long int x)
{
    unsigned long long int fact = 1 , i;
    for(i = 1; i <= x; i++)
        fact = fact * i;
    return fact;
}
