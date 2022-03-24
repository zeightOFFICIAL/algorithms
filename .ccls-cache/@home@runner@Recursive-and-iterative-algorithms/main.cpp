/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 3
Recursive and iterable algorithms
 - Fibonacci (recursion, iterative, tail-recursion)
 - Greatest common divisor (recursion, iterative)
 - Factorial (recursion, iterative)
main.cpp
24.03.2022
ver 1.04
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

//============================================================================

unsigned long long int UnaryEnveloper(unsigned long long int(*func)(unsigned long long int))
{
    unsigned long long int X = -1, N;
    clock_t t;
    while (1)  {
            cout << "Enter the number of terms: ";
            cin >> N;
            if (N<0 || N>10000000)
                cout<<"Warning: Enveloper: Wrong number of terms!";
            else
                break;
        }

    t = clock();
    X=func(N);
    t = clock()-t;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    cout<< N <<"-x element: "<< X << "\n";
    return X;
}

unsigned long long int BinaryEnveloper(unsigned long long int(*func)(unsigned long long int, unsigned long long int))
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
    t = t - clock()-t;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    cout<<"GCD is: " << R << "\n";
    return R;
}

unsigned long long int UnaryEnveloperForTailRecursion(unsigned long long int(*func)(unsigned long long int, unsigned long long int, unsigned long long int))
{
    unsigned long long int X = -1, N;
    clock_t t;
    while (1)  {
            cout << "Enter the number of terms: ";
            cin >> N;
            if (N<0 || N>10000000)
                cout<<"Warning: Enveloper: Wrong number of terms!";
            else
                break;
        }
    t = clock();
    X=func(N,0,1);
    t = clock()-t;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    cout<< N <<"-x element: "<< X << "\n";
    return X;
}
//============================================================================

int main() 
{
    cout<<"Start."<<"\n";

    cout<<UnaryEnveloperForTailRecursion(&FibonacciTailRecursive) << "\n";
    cout<<UnaryEnveloper(&FibonacciRecursive) << "\n";
    cout<<UnaryEnveloper(&FibonacciIterative) << "\n";

    //cout<<UnaryEnveloper(&FactorialRecursive) << "\n";
    //cout<<UnaryEnveloper(&FactorialIterative) << "\n";
    
    //cout<<BinaryEnveloper(&GCDIterative);
    //cout<<BinaryEnveloper(&GCDRecursive);
    
    cout<<"End."<<"\n";
}