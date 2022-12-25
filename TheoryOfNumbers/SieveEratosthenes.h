// SieveEratosthenes.h

#include <cstdint>
#include <vector>

namespace sieve {
  typedef uint64_t uint64;
  typedef unsigned long ulong;
  typedef std::vector<uint64> vector;
  
  /**
    (unsigned long A) -> (vector<uint64_t> B)
    Finds prime numbers within range of 0..A
    with a help of Eratosthenes' sieve.
    Returns vector which stores every prime number.
  */
  static vector eratosthenesSieve(ulong size);
  
  static vector eratosthenesSieve(ulong size) {
    if (size == 0) {
      return vector{0};
    }
    vector primes;
    bool sieve[size + 1];
  
    for (ulong fill = 0; fill <= size; fill++) {
      sieve[fill] = true;
    }
    for (ulong number = 2; number * number <= size; number++) {
      if (sieve[number] == true) {
        for (ulong notPrime = number * number; notPrime <= size; notPrime += number) {
          sieve[notPrime] = false;
        }
      }
    }
    for (unsigned long each = 2; each <= size; each++) {
      if (sieve[each]) {
        primes.push_back(each);
      }
    }
    
    return primes;
  }
} // namespace sieve