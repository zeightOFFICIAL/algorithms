// totalsum.h

#include <cstdint>

/*
    (uint64 A, uint64 B) -> (uint64 C)
    Finds sum of all elements in range A..B.
    And returns its value C. Uses recursion.
    >>SumRecursive(1,3)
    <<6
*/
uint64_t SumRecursive(uint64_t x, uint64_t y)
{
    if (y == x)
        return y;
    return y + SumRecursive(x, y - 1);
}
uint64_t SumIterative(uint64_t x, uint64_t y)
{
    uint64_t result = 0;
    for (uint64_t k = x; k <= y; k++)
        result = result + k;
    return result;
}