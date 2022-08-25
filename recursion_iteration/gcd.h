// gcd.h

/*
In mathematics, the greatest common divisor (GCD) of two or more integers,
which are not all zero, is the largest positive integer that divides each of
the integers. For two integers x, y, the greatest common divisor of x and y
is denoted gcd(x, y). For example, the GCD of 8 and 12 is 4.
https://en.wikipedia.org/wiki/Greatest_common_divisor
*/

#include <cstdint>

/*
	(uint64 A, uint64 B) -> (uint64 C)
	Finds GCD of numbers A and B and returns
	its value - C.
*/
uint64_t GCDRecursive(uint64_t x, uint64_t y)
{
	if (y == 0)
		return x;
	return GCDRecursive(y, x % y);
}
uint64_t GCDIterative(uint64_t x, uint64_t y)
{
	while (x != y) {
		if (x > y)
			x -= y;
		else
			y -= x;
	}
	return x;
}