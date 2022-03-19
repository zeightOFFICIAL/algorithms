/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 3
Recursive and iterable algorithms
 - Fibonacci
 - Greatest common divisor
 - Factorial
main.cpp
19.03.2022
ver 1.0
*/

#include <iostream>
#include <ctime>

#include "recursion_funcs.h"
#include "iteration_funcs.h"

using std::cout, std::cin;

/*
    (*func A)->(int N)->(uint64_t C)
    Envelopes the sequence function with recursion (or iteration) A.
    Takes N as a number of terms for this function A to find. Counts 
    time. Returns value C of func A(int N)
    >>enveloper_unary(&fibonacci_iterative)
    >>Enter the number of terms: 45
    <<45-x of sequence is: 1134903170
      Time: 5.27243 seconds
*/
unsigned long long int enveloper_unary(unsigned long long int(*func)(unsigned long long int));

/*
    (*func A)->(int B, int C)->(uint64_t D)
    Envelopes the GCD-function with recursion (or iteration) A.
    Takes B and C as a two numbers for function A to find and
    return the result, meaning GCD. Counts time.
    Returns value D of func(int B, int C)
    >>enveloper_binary(&greatest_common_divisort_iterative)
    >>Enter X: 10
    >>Enter Y: 5
    <<Greatest common divisor of 10 and 5 is 5
    <<Time: 4.5e-05 seconds
*/
unsigned long long int enveloper_binary(unsigned long long int(*func)(unsigned long long int, unsigned long long int));

//============================================================================

unsigned long long int enveloper_unary(unsigned long long int(*func)(unsigned long long int))
{
    unsigned long long int X = -1, N;
    clock_t t;
    while (1)  {
            cout << "Enter the number of terms: ";
            cin >> N;
            if (N<0 || N>1000000)
                cout<<"Warning: Enveloper: Wrong number of terms!";
            else
                break;
        }

    t = clock();
    X=func(N);
    cout<<N<<"-s of sequence is: "<<X<<"\n";
    t = clock()-t;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    return X;
}

unsigned long long int enveloper_binary(unsigned long long int(*func)(unsigned long long int, unsigned long long int))
{
    unsigned long long int y,x,R;
    clock_t t;
    while (1) {
            cout << "Enter X: ";
            cin >> x;
            cout << "Enter Y: ";
            cin >> y;
            if (x<=0 || y<0)
                cout<<"Warning: Enveloper: Wrong number!";
            else
                break;
        }
    
    t = clock();
    R=func(x,y);
    cout<<"Greatest common divisor of "<<x<<" and "<<y<<" is "<<R<<"\n";
    t = clock()-t;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    return R;
}

//============================================================================

int main() 
{
    cout<<"Start."<<"\n";
    
    //enveloper_unary(&fibonacci_recursive);
    //enveloper_unary(&fibonacci_iterative);
    
    //enveloper_unary(&factorial_recursive);
    //enveloper_unary(&factorial_iterative);
    
    //enveloper_binary(&greatest_common_divisor_recursive);
    //enveloper_binary(&greatest_common_divisor_iterative);
    
    cout<<"End."<<"\n";
}