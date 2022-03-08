#include "RecursionFuncs.h"

unsigned long long int Fibonacci(unsigned long long int x)
{
/*
    (unsigned long long int A)->(unsigned long long int B)
    Returns the A-s number of fibonacci sequence. If it's 
    1 returns 1, 0 returns 0.
    >>Fibonacci(45)
    <<1134903170
*/
    if((x==1)||(x==0))
        return(x);
    return(Fibonacci(x-1)+Fibonacci(x-2));
}

unsigned long long int Factorial(unsigned long long int x)
{
/*
    (unsigned long long int A)->(unsigned long long int B)
    Returns factorial of number A. If it's 1 returns 1, 
    0 returns 1.
    >>Factorial(0)
    <<1
*/
    if((x==1)||(x==0))
        return 1;
    return x*Factorial(x-1);
}

long int GCD(long int x, long int y)
{
/*
    (long int X,long int Y)->(long int R)
    Returns the greatest common divisor R of 
    number X and Y. If Y is equal to 0, returns
    0.
    >>GCD(10,5)
    <<5
*/
    if (y == 0)
        return x;
    return GCD(y, x % y);
}