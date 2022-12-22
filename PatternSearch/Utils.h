// Utils.h
// must be included and used in each pattern search header file
// for ver 1.31

#include <climits>
#include <string>
#include <vector>

#pragma once

namespace substrsearch {
typedef std::vector<unsigned long> vector;
typedef std::string string;
long long maxByValue(long long a, long long b) { return a >= b ? a : b; }
}