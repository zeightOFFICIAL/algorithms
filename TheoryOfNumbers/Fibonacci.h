/*
Zeight Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Fibonacci.h

#include <cstdint>

namespace fibonacci {
  typedef uint64_t uint64;
  typedef unsigned long ulong;
  static const uint64 PreGenFibonacci90[91] = {
   0,
   1,
   1,
   2,
   3,
   5,
   8,
   13,
   21,
   34,
   55,
   89,
   144,
   233,
   377,
   610,
   987,
   1597,
   2584,
   4181,
   6765,
   10946,
   17711,
   28657,
   46368,
   75025,
   121393,
   196418,
   317811,
   514229,
   832040,
   1346269,
   2178309,
   3524578,
   5702887,
   9227465,
   14930352,
   24157817,
   39088169,
   63245986,
   102334155,
   165580141,
   267914296,
   433494437,
   701408733,
   1134903170,
   1836311903,
   2971215073,
   4807526976,
   7778742049,
   12586269025,
   20365011074,
   32951280099,
   53316291173,
   86267571272,
   139583862445,
   225851433717,
   365435296162,
   591286729879,
   956722026041,
   1548008755920,
   2504730781961,
   4052739537881,
   6557470319842,
   10610209857723,
   17167680177565,
   27777890035288,
   44945570212853,
   72723460248141,
   117669030460994,
   190392490709135,
   308061521170129,
   498454011879264,
   806515533049393,
   1304969544928657,
   2111485077978050,
   3416454622906707,
   5527939700884757,
   8944394323791464,
   14472334024676221,
   23416728348467685,
   37889062373143906,
   61305790721611591,
   99194853094755497,
   160500643816367088,
   259695496911122585,
   420196140727489673,
   679891637638612258,
   1100087778366101931,
   1779979416004714189,
   2880067194370816120};
  /**
    (uint64_t A) -> (uint64_t B)
    Finds A-x element of fibonacci sequence.
    Uses recursion. Returns B.
  */
  static uint64 RecursiveFibonacci(uint64 term);
  /**
    (uint64_t A) -> (uint64_t B)
    Finds A-x element of fibonacci sequence.
    Uses pure recursion. Returns B.
  */
  static uint64 PureRecursiveFibonacci(uint64 term, uint64 a = 0, uint64 b = 1);
  /**
    (uint64_t A) -> (uint64_t B)
    Finds A-x element of fibonacci sequence.
    Uses iteration. Returns B.
  */
  static uint64 IterativeFibonacci(ulong term);
  
  static uint64 RecursiveFibonacci(uint64 term) {
    if (term > 90) {
      return 0;
    }
    
    if ((term == 1) || (term == 0)) {
      return (term);
    }
    
    return (RecursiveFibonacci(term - 1) + RecursiveFibonacci(term - 2));
  }

  static uint64 PureRecursiveFibonacci(uint64 term, uint64 a, uint64 b) {
    if (term > 90) {
      return 0;
    }
    
    if (term == 0) {
      return a;
    }
    if (term == 1) {
      return b;
    }
    
    return PureRecursiveFibonacci(term - 1, b, a + b);
  }

  static uint64 IterativeFibonacci(ulong term) {
    if (term > 90) {
      return 0;
    }
    uint64 result = 0, x = 1, y = 0;
    ulong index;
    
    for (index = 0; index < term; index++) {
      y = result + x;
      result = x;
      x = y;
    }
    
    return result;
  }
} // namespace fibonacci