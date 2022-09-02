// euclidean_gcd.h

/*
In mathematics, the greatest common divisor (GCD) of two or more integers,
which are not all zero, is the largest positive integer that divides each of
the integers. For two integers x, y, the greatest common divisor of x and y
is denoted gcd(x, y). For example, the GCD of 8 and 12 is 4.

In mathematics, the Euclidean algorithm, or Euclid's algorithm, is 
an efficient method for computing the greatest common divisor (GCD) of two
integers (numbers), the largest number that divides them both without a
remainder.

https://en.wikipedia.org/wiki/Greatest_common_divisor
https://en.wikipedia.org/wiki/Euclidean_algorithm
*/

#include <cstdint>

uint64_t EuclideanGCDRecursive(uint64_t x, uint64_t y);
uint64_t EuclideanGCDIterative(uint64_t x, uint64_t y);

/*
	(uint64 A, uint64 B) -> (uint64 C)
	Finds GCD of numbers A and B and returns
	its value - C. Uses recursion.
*/
uint64_t EuclideanGCDRecursive(uint64_t x, uint64_t y)
{
	if (y == 0)
		return x;
	return EuclideanGCDRecursive(y, x % y);
}

/*
	(uint64 A, uint64 B) -> (uint64 C)
	Finds GCD of numbers A and B and returns
	its value - C. Uses iteration.
*/
uint64_t EuclideanGCDIterative(uint64_t x, uint64_t y)
{
	while (x != y) {
		if (x > y)
			x -= y;
		else
			y -= x;
	}
	return x;
}