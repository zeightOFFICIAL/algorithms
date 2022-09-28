// naive_summation.h

#include <vector>

template <typename T>
T NaiveSumRecursive(std::vector<T> x);
template <typename T>
T NaiveSumIterative(std::vector<T> x);

/*
    (vector T A)->(T B)
    Finds the sum of elements in vector A.
    Returns B.
*/
template <typename T>
T NaiveSumRecursive(std::vector<T> x)
{
    if (x.size() == 1)
        return x[0];
    T value = x[x.size()-1];
    x.pop_back();
    return value + NaiveSumRecursive(x);
}

template <typename T>
T NaiveSumIterative(std::vector<T> x)
{
    T result = 0;
    for (T value : x)
            result = result + value;
	return result;
}