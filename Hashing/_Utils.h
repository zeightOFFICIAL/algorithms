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
  typedef unsigned long u_long;
  typedef uint64_t uint64;
  typedef uint32_t uint32;
  typedef std::stringstream strstream;
  typedef std::vector<uint32_t> vector;
  typedef std::bitset<8> bitset8;

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