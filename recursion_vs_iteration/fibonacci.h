#pragma once
/*
    (uint64 A) -> (uint64 B)
    Finds A-x element of fibonacci sequence
    and returns its value - B. Uses recursion.
    >>FibonacciRecursive(19)
    <<4181
*/
unsigned long long FibonacciRecursive(unsigned long long x);
/*
    (uint64 A, B, C) -> (uint64 D)
    Finds A-x element of fibonacci sequence
    and returns its value - D. Uses tail-recursion
    >>FibonacciTailRecursive(19)
    <<4181
)
*/
unsigned long long FibonacciTailRecursive(unsigned long long x, unsigned long long a = 0, unsigned long long b = 1);
/*
    (uint64 A) -> (uint32 B)
    Finds A-x element of fibonacci sequence
    and returns its value - B. Uses iteration.
    >>fibonacci_iterative(19)
    <<4181
*/
unsigned long long FibonacciIterative(unsigned int n);