/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V, Kuksin A.A
Lab 3
Recursive and iterable algorithms, comparison (time and difficulty)  
 - Fibonacci (recursive)
 - Greatest common divisor (recursive)
 -
main.cpp
08.03.2022
ver 0.5
*/

#include <iostream>
#include <cmath>
#include <ctime>

#include "RecursionFuncs.h"
#include "IterationFuncs.h"

using namespace std;

void Enveloper(unsigned long long int(*func)(unsigned long long int));
void Enveloper_BIN(long int(*func)(long int, long int));


void Enveloper(unsigned long long int(*func)(unsigned long long int))
{
/*
    (*func A)->(int N)->()
    Envelopes the sequence function with recursion (or iteration) A.
    Takes N as a number of terms for this function A to find. Counts 
    time.
    Returns nothing.
    >>Enveloper(&Fibonacci)
    >>Enter the number of terms: 45
    <<45-s of sequence is: 1134903170
      Time: 5.27243 seconds
*/
    int N;
    unsigned long long int X = -1;
    while (1)
        {
            cout << "Enter the number of terms: ";
            cin >> N;
            if (N<0 || N>1000000)
                cout<<"Warning: Enveloper: Wrong number of terms!";
            else
                break;
        }

    clock_t t;
    t = clock();
    
    X=func(N);
    cout<<N<<"-s of sequence is: "<<X<<endl;

    t = clock()-t;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
}

void Enveloper_BIN(long int(*func)(long int, long int))
{
/*
    (*func A)->(int B, int C)->()
    Envelopes the GCD-function with recursion (or iteration) A.
    Takes B and C as a two numbers for function A to find and
    return the result, meaning GCD. Counts time.
    Returns nothing.
    >>Envelope_BIN(&GCD)
    >>Enter X: 10
    >>Enter Y: 5
    <<Greatest common divisor of 10 and 5 is 5
    <<Time: 4.5e-05 seconds
*/
    long int y,x;
    long int R;

    while (1)
        {
            cout << "Enter X: ";
            cin >> x;
            cout << "Enter Y: ";
            cin >> y;
            if (x<=0 || y<0)
                cout<<"Warning: Enveloper: Wrong number!";
            else
                break;
        }

    clock_t t;
    t = clock();

    R=func(x,y);
    cout<<"Greatest common divisor of "<<x<<" and "<<y<<" is "<<R<<endl;

    t = clock()-t;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
}

int main() 
{
    cout<<"Start."<<"\n=========================================================\n";

    Enveloper(&Fibonacci_ITER);
    //Enveloper_BIN(&GCD);
    
    cout<<"End."<<"\n=========================================================";
}