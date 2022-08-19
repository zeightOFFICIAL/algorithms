#pragma once
/*
    (uint64 A, uint64 B) -> (uint64 C)
    Finds sum of all elements in range A..B.
    And returns its value C. Uses recursion.
    >>SumRecursive(1,3)
    <<6
*/
unsigned long long SumRecursive(unsigned long long x, unsigned long long y);
/*
    (uint64 A, uint64 B) -> (uint64 C)
    Finds sum of all elements in range A..B.
    And returns its value C. Uses iteration.
    >>SumIterative(1,3)
    <<6
*/
unsigned long long SumIterative(unsigned long long x, unsigned long long y);