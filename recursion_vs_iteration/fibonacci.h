/*
    (uint64_t A) -> (uint64_t B)
    Finds A-x element of fibonacci sequence
    and returns its value - B. Uses recursion.
    >>FibonacciRecursive(19)
    <<4181
*/
unsigned long long int FibonacciRecursive(unsigned long long int x);

/*
    (uint64_t A, B, C) -> (uint64_t D)
    Finds A-x element of fibonacci sequence
    and returns its value - D. Uses tail-recursion
    >>FibonacciTailRecursive(19)
    <<4181
)
*/
unsigned long long int FibonacciTailRecursive(unsigned long long int x, unsigned long long int a = 0, unsigned long long int b = 1);

/*
    (uint64_t A) -> (uint64_t B)
    Finds A-x element of fibonacci sequence
    and returns its value - B. Uses iteration.
    >>fibonacci_iterative(19)
    <<4181
*/
unsigned long long int FibonacciIterative(unsigned long long int n);