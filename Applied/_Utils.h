// Utils.h
// must be included and used in each hashing header file
// for ver 1.32

#pragma once

#include <string>

namespace easterday {
  typedef std::string string;
  typedef unsigned long ulong;

  static const string monthName[12] = {
      "January", "February", "March",     "April",   "May",      "June",
      "July",    "August",   "September", "October", "November", "December"};
}