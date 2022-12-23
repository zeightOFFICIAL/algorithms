// Utils.h
// must be included and used in each sorting header file
// for ver 1.32

#include <climits>
#include <string>
#include <vector>

#pragma once

namespace patternsearch {
  typedef std::vector<unsigned long> vector;
  typedef std::string string;
  typedef unsigned long u_long;
  typedef long long long64;

  long64 maxByValue(long64 a, long64 b) { return a >= b ? a : b; }
} // namespace substrsearch