#pragma once
/*
    (uint64 A) -> (uint64 B)
    Finds factorial of number A and returns
    its value - B. Uses recursion.
    >>FactorialRecursive(3)
    <<6
*/
unsigned long long FactorialRecursive(unsigned long long x);
/*
    (uint64 A) -> (uint32 B)
    Finds factorial of number A and returns
    its value - B. Uses iteration.
    >>FactorialIterative(3)
    <<6
*/
unsigned long long FactorialIterative(unsigned int x);