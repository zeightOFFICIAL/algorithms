// stein_gcd.h

/*
In mathematics, the greatest common divisor (GCD) of two or more integers,
which are not all zero, is the largest positive integer that divides each of
the integers. For two integers x, y, the greatest common divisor of x and y
is denoted gcd(x, y). For example, the GCD of 8 and 12 is 4.

Stein’s algorithm or binary GCD algorithm is an algorithm that computes the 
greatest common divisor of two non-negative integers. Stein’s algorithm 
replaces division with arithmetic shifts, comparisons, and subtraction.

https://en.wikipedia.org/wiki/Greatest_common_divisor
https://www.geeksforgeeks.org/steins-algorithm-for-finding-gcd/
*/

#include <cstdint>

typedef unsigned long long u_d_long;

uint64_t SteinGCDRecursive(uint64_t x, uint64_t y);
uint64_t SteinGCDIterative(uint64_t x, uint64_t y);

/*
	(uint64 A, uint64 B) -> (uint64 C)
	Finds GCD of numbers A and B and returns
	its value - C. Uses recursion.
*/
uint64_t SteinGCDRecursive(uint64_t x, uint64_t y)
{
    if (x == y)
        return x;
    if (x == 0)
        return y;
    if (y == 0)
        return x;
    
        
	return 0;
}

/*
	(uint64 A, uint64 B) -> (uint64 C)
	Finds GCD of numbers A and B and returns
	its value - C. Uses iteration.
*/
uint64_t SteinGCDIterative(uint64_t x, uint64_t y)
{
	if (x == 0)
        return y;
    if (y == 0)
        return x;
    u_d_long k;
    for (k = 0; ((x | y) & 1) == 0; k++) {
        x >>= 1;
        y >>= 1;
    }
    while ((x & 1) == 0)
        x >>= 1;
    do
        {
            while ((y & 1) == 0)
                y >>= 1;
            if (x > y)
                std::swap(x, y);
            y = (y - x);
        } while (y != 0);
    return x << k;    
}