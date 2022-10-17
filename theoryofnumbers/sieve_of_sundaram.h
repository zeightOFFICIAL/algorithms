// sieve_of_sundaram.h

/*
In mathematics, the sieve of Sundaram is a variant of the sieve of
Eratosthenes, a simple deterministic algorithm for finding all the
prime numbers up to a specified integer. It was discovered by
Indian student S. P. Sundaram in 1934.
https://en.wikipedia.org/wiki/Sieve_of_Sundaram
*/

#include <vector>

std::vector<unsigned long> SundaramPrimes(unsigned long n);

/*
    (u_long A) -> (vector<u_long> B)
    Finds prime numbers within range of 0..A
    with a help of Sundaram's sieve. Returns
    vector which stores every prime number.
*/
std::vector<unsigned long> SundaramPrimes(unsigned long n) {
  std::vector<unsigned long> primes;
  n = n / 2;
  unsigned long k = (n - 2) / 2;
  bool sieve[n + 1];
  for (unsigned long i = 1; i <= n; i++)
    sieve[i] = true;
  for (unsigned long i = 1; 2 * i * (i + 1) < n; i++) {
    unsigned long j_max = (n - 1) / (2 * i + 1);
    for (unsigned long j = i; j <= j_max; j++)
      sieve[2 * i * j + i + j] = false;
  }
  for (unsigned long i = 1; i <= n; i++)
    if (sieve[i])
      primes.push_back(2 * i + 1);

  return primes;
}