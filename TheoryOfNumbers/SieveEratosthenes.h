// sieve_of_eratosthenes.h

#include <vector> // vector

/*
  (u_long A) -> (vector<u_long> B)
  Finds prime numbers within range of 0..A
  with a help of Eratosthenes' sieve.
  -Returns vector which stores every prime number.
*/
std::vector<unsigned long> primesEratosthenes(unsigned long n);

std::vector<unsigned long> primesEratosthenes(unsigned long n) {
  std::vector<unsigned long> primes;
  bool sieve[n + 1];
  for (unsigned long i = 0; i <= n; i++)
    sieve[i] = true;
  for (unsigned long i = 2; i * i <= n; i++) {
    if (sieve[i] == true)
      for (unsigned long j = i * i; j <= n; j += i)
        sieve[j] = false;
  }
  for (unsigned long i = 2; i <= n; i++)
    if (sieve[i])
      primes.push_back(i);
  return primes;
}