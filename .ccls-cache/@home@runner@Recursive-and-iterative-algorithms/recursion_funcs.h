/**
    (uint64_t A) -> (uint64_t B)
    Finds A-x element of fibonacci sequence
    and returns its value - B. Uses recursion.
    >>FibonacciRecursive(19)
    <<4181
*/
unsigned long long int FibonacciRecursive(unsigned long long int x);

/**
    (uint64_t A, B, C) -> (uint64_t D)
    Finds A-x element of fibonacci sequence
    and returns its value - D. Uses tail-recursion
    >>FibonacciTailRecursive(19)
    <<4181
)
*/
unsigned long long int FibonacciTailRecursive(unsigned long long int n, unsigned long long int a = 0, unsigned long long int b = 1);

/**
    (uint64_t A) -> (uint64_t B)
    Finds factorial of number A and returns
    its value - B. Uses recursion.
    >>FactorialRecursive(3)
    <<6
*/
unsigned long long int FactorialRecursive(unsigned long long int x);

/**
    (uint64_t A, uint64_t B) -> (uint64_t C)
    Finds GCD of numbers A and B and returns
    its value - C. Uses recursion.
    >>GCDRecursive(15,5)
    <<5
*/
unsigned long long int GCDRecursive(unsigned long long int x, unsigned long long int y);