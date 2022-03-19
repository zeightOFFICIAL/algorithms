/**
    (uint64_t A) -> (uint64_t B)
    Finds A-x element of fibonacci sequence
    and returns its value - B. Uses recursion.
    >>fibonacci_recursive(19)
    <<4181
*/
unsigned long long int fibonacii_recursive(unsigned long long int x);

/**
    (uint64_t A) -> (uint64_t B)
    Finds factorial of number A and returns
    its value - B. Uses recursion.
    >>factorial_recursive(3)
    <<6
*/
unsigned long long int factorial_recursive(unsigned long long int x);

/**
    (uint64_t A, uint64_t B) -> (uint64_t C)
    Finds GCD of numbers A and B and returns
    its value - C. Uses recursion.
    >>greatest_common_divisor(15,5)
    <<5
*/
unsigned long long int greatest_common_divisor(unsigned long long int x, unsigned long long int y);
