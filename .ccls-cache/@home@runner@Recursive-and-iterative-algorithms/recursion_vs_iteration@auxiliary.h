/*
    (*func A)->(int N)->(uint64_t C)
    Envelopes the sequence function with recursion (or iteration) A.
    Takes N as a number of terms for this function A to find. Counts 
    time. Returns value C of func A(int N)
    >>UnaryEnveloper(&FibonacciIterative)
    >>Enter the number of terms: 45
    <<45-x element: 1134903170
      Time: 5.27243 seconds
*/
unsigned long long int UnaryEnveloper(unsigned long long int(*func)(unsigned long long int));

/*
    (*func A)->(int B, int C)->(uint64_t D)
    Envelopes the GCD-function with recursion (or iteration) A.
    Takes B and C as a two numbers for function A to find and
    return the result, meaning GCD. Counts time.
    Returns value D of func(int B, int C)
    >>BinaryEnveloper(&GCDIterative)
    >>Enter X: 10
    >>Enter Y: 5
    <<GCD: 5
    <<Time: 4.5e-05 seconds
*/
unsigned long long int BinaryEnveloper(unsigned long long int(*func)(unsigned long long int, unsigned long long int));

/*
    (*func A)->(int N)->(uint64_t C)
    Envelopes the sequence function with recursion (or iteration) A.
    Takes N as a number of terms for this function A to find. Counts 
    time. Returns value C of func A(int N)
    >>UnaryEnveloper(&FibonacciTailRecursion)
    >>Enter the number of terms: 45
    <<45-x element: 1134903170
      Time: 5.27243 seconds
*/
unsigned long long int UnaryEnveloperForTailRecursion(unsigned long long int(*func)(unsigned long long int, unsigned long long int, unsigned long long int));
