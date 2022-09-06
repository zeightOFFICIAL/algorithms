// sieve_of_eratosthenes.h

/*
In mathematics, the sieve of Eratosthenes is an ancient algorithm 
for finding all prime numbers up to any given limit.
https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
*/

#include <vector>

typedef unsigned long u_long;
std::vector<u_long> EratosthenesPrimes(u_long n);

/*
    (u_long A) -> (vector<u_long> B)
    Finds prime numbers within range of 0..A 
    with a help of Eratosthenes' sieve. Returns 
    vector which stores every prime number.
*/
std::vector<u_long> EratosthenesPrimes(u_long n) 
{
    std::vector<u_long> primes;
    bool sieve[n+1];
    for (u_long i = 0; i <= n; i++)
        sieve[i] = true;
    for (u_long i = 2; i * i <= n; i++) {
        if (sieve[i] == true)
            for (u_long j = i * i; j <= n; j += i)
                sieve[j] = false;
    }
    for (u_long i = 0; i <= n; i++)
        if (sieve[i])
            primes.push_back(i);
    return primes;
}