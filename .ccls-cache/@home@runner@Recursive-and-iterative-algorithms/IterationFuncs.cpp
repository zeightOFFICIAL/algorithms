#include "IterationFuncs.h"

unsigned long long int Fibonacci_ITER(unsigned long long int num)
{
/*
    (unsigned long long int A)->(unsigned long long int B)
    Returns the A-s number of fibonacci sequence. If it's 
    1 returns 1, 0 returns 0.
    >>Fibonacci(45)
    <<1134903170
*/
    int x = 0, y = 1, z = 0;
    for (int i = 0; i < num; i++) {
        z = x + y;
        x = y;
        y = z;
    }
    return x;
}

unsigned long long int Factorial_ITER(unsigned long long int num)
{
/*
    (unsigned long long int A)->(unsigned long long int B)
    Returns factorial of number A. If it's 1 returns 1, 
    0 returns 1.
    >>Factorial(0)
    <<1
*/
    unsigned long long int fact,i;
    fact = 1;
    for(i=1; i<=num; i++)
        fact = fact*i;
    return fact;
}

long int GCD_ITER(long int x, long int y)
{
/*
    (long int X,long int Y)->(long int R)
    Returns the greatest common divisor R of 
    number X and Y. If Y is equal to 0, returns
    0.
    >>GCD(10,5)
    <<5
*/
    while(x != y) {
    if(x > y)
      x -= y;
    else
      y -= x;
    }
    return x;
}