#pragma once
/*
    (uint64 A, uint64 B) -> (uint64 C)
    Finds GCD of numbers A and B and returns
    its value - C. Uses recursion.
    >>GCDRecursive(15,5)
    <<5
*/
unsigned long long GCDRecursive(unsigned long long x, unsigned long long y);
/*
    (uint64 A, uint64 B) -> (uint64 C)
    Finds GCD of numbers A and B and returns
    its value - C. Uses iteration.
    >>GCDIterative(15,5)
    <<5
*/
unsigned long long GCDIterative(unsigned long long x, unsigned long long y);