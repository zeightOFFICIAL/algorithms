/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 3
Recursive and iterable algorithms
- Fibonacci (recursion, iterative, tail-recursion)
- Greatest common divisor (recursion, iterative)
- Factorial (tail-recursion, iterative)
- Sum of numbers in interval (tail-recursion)
main.cpp
04.04.2022
ver 1.060
*/

#include <iostream>
#include <ctime>

#include "recursion_vs_iteration/auxiliary.h"
#include "recursion_vs_iteration/factorial.h"
#include "recursion_vs_iteration/fibonacci.h"
#include "recursion_vs_iteration/gcd.h"
#include "recursion_vs_iteration/totalsum.h"

using std::cout, std::cin;


int main() 
{
    cout<<"Start."<<"\n";
    //...............................................

    //cout<<UnaryEnveloperForTailRecursion(&FibonacciTailRecursive) << "\n";
    //cout<<UnaryEnveloper(&FibonacciRecursive) << "\n";
    //cout<<UnaryEnveloper(&FibonacciIterative) << "\n";

    //cout<<UnaryEnveloper(&FactorialRecursive) << "\n";
    //cout<<UnaryEnveloper(&FactorialIterative) << "\n";
    
    //cout<<BinaryEnveloper(&GCDIterative);
    //cout<<BinaryEnveloper(&GCDRecursive);
    
    //cout<<BinaryEnveloper(&SumIterative);
    //cout<<BinaryEnveloper(&SumRecursive);

    //.....................................................................................
    /*
    long double alltime = 0, alltime2 = 0, alltime3 = 0;
    int tries;
    clock_t t;
    unsigned long long n, x;
    cin >> n;
    cin >> x;
    for(tries = 0; tries < 1; tries++)
        {
            //t = clock();
            //FibonacciRecursive(n);
            //t = clock()-t;
            //alltime = alltime + ((float)t)/CLOCKS_PER_SEC;
            
            t = clock();
            GCDRecursive(n,x);
            t = clock()-t;
            alltime2 = alltime2 + ((float)t)/CLOCKS_PER_SEC;

            t = clock();
            GCDIterative(n,x);
            t = clock()-t;
            alltime3 = alltime3 + ((float)t)/CLOCKS_PER_SEC;
        }
    cout<<"Average time: "<<alltime/tries<<" seconds"<<"\n";
    cout<<"Average time: "<<alltime2/tries<<" seconds"<<"\n";
    cout<<"Average time: "<<alltime3/tries<<" seconds"<<"\n";
    */
    //.....................................................................................

    //...............................................
    cout<<"End."<<"\n";
}