/*
Zeight Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

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
  typedef unsigned long ulong;
  typedef int64_t int64;

  static int64 maxByValue(int64 a, int64 b) { return a >= b ? a : b; }
} // namespace substrsearch