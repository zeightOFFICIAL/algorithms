// stein_gcd.h

/*
Stein’s algorithm or binary GCD algorithm is an algorithm that computes the 
greatest common divisor of two non-negative integers. Stein’s algorithm 
replaces division with arithmetic shifts, comparisons, and subtraction.

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
    if (~x & 1)
    {
        if (y & 1)
            return SteinGCDRecursive(x >> 1, y);
        else
            return SteinGCDRecursive(x >> 1, y >> 1) << 1;
    }
    if (~y & 1)
        return SteinGCDRecursive(x, y >> 1);
    if (x > y)
        return SteinGCDRecursive((x - y) >> 1, y);
	return SteinGCDRecursive((y - x) >> 1, x);
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