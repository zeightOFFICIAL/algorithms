// Utils.h
// must be included and used in each patternsearch header file
// for ver 1.32

#pragma once

#include <climits>
#include <string>
#include <vector>

namespace patternsearch {
  typedef std::vector<unsigned long> vector;
  typedef std::string string;
  typedef unsigned long u_long;
  typedef long long long64;

  static long64 maxByValue(long64 a, long64 b) { return a >= b ? a : b; }
} // namespace substrsearch