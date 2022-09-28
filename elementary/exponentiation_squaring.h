// exponentiation_squaring.h

/*
In mathematics and computer programming, exponentiating by 
squaring is a general method for fast computation of large 
positive integer powers of a number, or more generally of 
an element of a semigroup, like a polynomial or a square 
matrix. Some variants are commonly referred to as 
square-and-multiply algorithms or binary exponentiation. 
These can be of quite general use, for example in modular 
arithmetic or powering of matrices. For semigroups for 
which additive notation is commonly used, like elliptic 
curves used in cryptography, this method is also referred
to as double-and-add.

https://en.wikipedia.org/wiki/Exponentiation_by_squaring
*/

#include "math.h"

#define PRIME 1000000007

typedef unsigned long long d_u_long;
d_u_long ExponentiationSquaringRecursive(d_u_long x, d_u_long n);
d_u_long ExponentiationSquaringRecursive2(d_u_long x, d_u_long n);
d_u_long ExponentiationSquaringIterative(d_u_long x, d_u_long n);
d_u_long ExponentiationSquaringIterative2(d_u_long x, d_u_long n);

/*
    (unsigned long long A, unsigned long long B)->(unsigned long long C)
    Finds C of the A^B=C equation.
    Returns the number C.
*/
d_u_long ExponentiationSquaringRecursive(d_u_long x, d_u_long n)
{
    if (n < 0)
        return ExponentiationSquaringRecursive(1/x, -n);
    else if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return ExponentiationSquaringRecursive(x*x, n/2);
    else if (n % 2 != 0)
        return x*ExponentiationSquaringRecursive(x*x, (n-1)/2);
    return -1;
}
d_u_long ExponentiationSquaringRecursive2(d_u_long x, d_u_long n)
{
    if(n == 0)
        return 1;
    else if (n == 1)
        return x % PRIME;
    d_u_long next = ExponentiationSquaringRecursive(x, n / 2);
    next = (next * next) % PRIME;
    if (n % 2 == 0)
        return next;
    else
        return ((x % PRIME) * next) % PRIME;
}
d_u_long ExponentiationSquaringIterative(d_u_long x, d_u_long n)
{
    d_u_long y;
    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }
    if (n == 0)
        return 1;
    y = 1;
    while (n > 1)
        {
            if (n % 2 == 0)
            {
                x = x*x;
                n = n/2;
            }
            else
            {
                y = x*y;
                x = x*x;
                n = (n-1)/2;
            }
        }
    return x*y;
}
d_u_long ExponentiationSquaringIterative2(d_u_long x, d_u_long n)
{
    d_u_long y = 1L;
    while (n > 0)
        {
            if (n % 2 != 0)
                y = (y * x) % PRIME;
            x = (x*x) % PRIME;
            n = n/2;
        }
    return y % PRIME;
}