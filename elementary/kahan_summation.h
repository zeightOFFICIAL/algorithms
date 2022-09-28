// kahan_summation.h

/*
Kahan summation algorithm, also known as compensated summation 
and summation with the carry algorithm, is used to minimize the 
loss of significance in the total result obtained by adding a 
sequence of finite-precision floating-point numbers. This is 
done by keeping a separate running compensation (a variable 
to accumulate small errors). 

https://www.geeksforgeeks.org/kahan-summation-algorithm/
*/

#include <vector>

template <typename T>
T KahanSummation(std::vector<T> x);

/*
    (vector long double A)->(long double B)
    Finds the sum of elements in vector A.
    Returns B.
*/
template <typename T>
T KahanSummation(std::vector<T> x)
{
    T result = 0.0f, c = 0.0f;
    for(T value : x)
    {
        T y = value - c;
        T m = result + y;
        c = (m - result) - y;
        result = m;
    }
    return result;
}