/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// SieveSundaram.h

#include <cstdint>
#include <vector>

namespace sieve {
  typedef uint64_t uint64;
  typedef unsigned long ulong;
  typedef std::vector<uint64> vector;
  /**
    (unsigned long A) -> (vector<uint64_t> B)
    Finds prime numbers within range of 0..A
    with a help of Sundaram's sieve.
    Returns vector which stores every prime number.
  */
  static vector SundaramSieve(ulong size);
  
  static vector SundaramSieve(ulong size) {
    if (size == 0) {
      return vector{0};
    }
    vector primes;
    static ulong newSize = (size - 1) / 2;
    vector sieve;
    sieve.resize(size + 1, false);
  
    for (ulong each = 1; each <= newSize; each++) {
      for (ulong yesPrime = each; (each + yesPrime + 2 * each * yesPrime) <= newSize; yesPrime++) {
        sieve[each + yesPrime + 2 * each * yesPrime] = true;
      }
    }
    if (size > 2) {
      primes.push_back(2);
    }
    for (ulong each = 1; each <= newSize; each++) {
      if (sieve[each] == false) {
        primes.push_back(2 * each + 1);
      }
    }
  
    return primes;
  }
} // namespace sieve