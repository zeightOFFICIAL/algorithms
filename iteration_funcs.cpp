#include "iteration_funcs.h"

unsigned long long int fibonacci_iterative(unsigned long long int num)
{
    unsigned long long int x = 0, y = 1, z = 0;
    for (int i = 0; i < num; i++) {
        z = x + y;
        x = y;
        y = z;
    }
    return x;
}

unsigned long long int factorial_iterative(unsigned long long int num)
{
    unsigned long long int fact,i;
    fact = 1;
    for(i=1; i<=num; i++)
        fact = fact*i;
    return fact;
}

unsigned long long int greatest_common_divisor_iterative(unsigned long long int x, unsigned long long int y)
{
    while(x != y) {
    if(x > y)
      x -= y;
    else
      y -= x;
    }
    return x;
}