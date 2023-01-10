/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Utils.h
// must be included and used in each hashing header file
// for ver 1.32

#pragma once

#include <climits>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>

namespace hashing {
  typedef std::string string;
  typedef unsigned long ulong;
  typedef uint64_t uint64;
  typedef uint32_t uint32;
  typedef std::stringstream strstream;
  typedef std::vector<uint32_t> vector;
  typedef std::bitset<8> bitset8;
  typedef std::bitset<32> bitset32;

  /**
  (T A) -> (string B)
  Converts A to hexadecimal contained in string B.
  Return string B.
  */
  template <typename T>
  static string intToHex(T number) {
    strstream stream;
    stream << "0x" 
           << std::setfill ('0') 
           << std::setw(sizeof(T)*2) 
           << std::hex << number;
    return stream.str();
  }
} // namespace hashing