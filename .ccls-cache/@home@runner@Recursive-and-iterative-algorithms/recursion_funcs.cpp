#include "recursion_funcs.h"

unsigned long long int fibonacci_recursive(unsigned long long int x)
{
    if((x==1)||(x==0))
        return(x);
    return(fibonacci_recursive(x-1)+fibonacci_recursive(x-2));
}

unsigned long long int factorial_recursive(unsigned long long int x)
{
    if((x==1)||(x==0))
        return 1;
    return x*factorial_recursive(x-1);
}

unsigned long long int greatest_common_divisor_recursive(unsigned long long int x, unsigned long long int y)
{
    if (y == 0)
        return x;
    return greatest_common_divisor_recursive(y, x % y);
}