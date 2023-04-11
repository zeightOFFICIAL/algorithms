/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// fletcher.h

#include "_Utils.h"
#include <iostream>

namespace hashing {
  /**
  (string A) -> (string B)
  Creates checksum B of string A, using
  fletcher 8bit hashing function. 
  Return string B - checksum.
  */
  static string fletcher16(const string data);
  /**
  (string A) -> (string B)
  Creates checksum B of string A, using
  fletcher 16bit hashing function. 
  Return string B - checksum.
  */
  static string fletcher32(const string data);

  static string fletcher16(const string data) {
    uint16 a = 0xff, b = 0xff;
    for (char c : data) {
      a += static_cast<uint8>(c);
      b += a;
    }
    a %= 0xff;
    b %= 0xff;

    uint16 res = (b << 8) | a;
    
    return intToHex(res);
  }

  static string fletcher32(const string data) {

  }
} // namespace hashing