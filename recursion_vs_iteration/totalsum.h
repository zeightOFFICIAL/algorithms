/*
    (uint64_t A, uint64_t B) -> (uint64_t C)
    Finds sum of all elements in range A..B.
    And returns its value C. Uses recursion.
    >>SumRecursive(1,3)
    <<6
*/
unsigned long long int SumRecursive(unsigned long long int x, unsigned long long int y);
/*
    (uint64_t A, uint64_t B) -> (uint64_t C)
    Finds sum of all elements in range A..B.
    And returns its value C. Uses iteration.
    >>SumIterative(1,3)
    <<6
*/
unsigned long long int SumIterative(unsigned long long int x, unsigned long long int y);