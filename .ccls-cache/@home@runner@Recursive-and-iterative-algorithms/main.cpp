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
31.03.2022
ver 1.057
*/

#include <iostream>
#include <ctime>

#include "recursion_vs_iteration/auxiliary.h"
#include "recursion_vs_iteration/factorial.h"
#include "recursion_vs_iteration/fibonacci.h"
#include "recursion_vs_iteration/gcd.h"

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

    //.....................................................................................
    long double alltime = 0;
    int tries;
    clock_t t;
     for(tries = 0; tries < 1000; tries++)
        {
            t = clock();
            FibonacciRecursive(40);
            t = clock()-t;
            alltime = alltime + ((float)t)/CLOCKS_PER_SEC;
        }
    cout<<"Average time: "<<alltime/tries<<" seconds"<<"\n";
    //.....................................................................................

    //...............................................
    cout<<"End."<<"\n";
}