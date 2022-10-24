// sieve_of_sundaram.h

/*
In mathematics, the sieve of Sundaram is a variant of the sieve of
Eratosthenes, a simple deterministic algorithm for finding all the
prime numbers up to a specified integer. It was discovered by
Indian student S. P. Sundaram in 1934.

https://en.wikipedia.org/wiki/Sieve_of_Sundaram
*/

#include <vector> // vector

/*
  (u_long A) -> (vector<u_long> B)
  Finds prime numbers within range of 0..A
  with a help of Sundaram's sieve.
  -Returns vector which stores every prime number.
*/
std::vector<unsigned long> primesSundaram(unsigned long n);

std::vector<unsigned long> primesSundaram(unsigned long n) {
  std::vector<unsigned long> primes;
  unsigned long newN = (n - 1) / 2;
  bool sieve[newN + 1];
  for (unsigned long i = 0; i < newN + 1; i++)
    sieve[i] = false;
  for (unsigned long i = 1; i <= newN; i++)
    for (unsigned long j = i; (i + j + 2 * i * j) <= newN; j++)
      sieve[i + j + 2 * i * j] = true;
  if (n > 2)
    primes.push_back(2);
  for (unsigned long i = 1; i <= newN; i++)
    if (sieve[i] == false)
      primes.push_back(2 * i + 1);
  return primes;
}