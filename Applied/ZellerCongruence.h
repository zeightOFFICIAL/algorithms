// ZellerCongruence.h

#include <string>

namespace applied {
  typedef std::string string;
  typedef unsigned long ulong;
  static string ZellerCongruence(ulong day, ulong month, ulong year);
  
  static const string callings[7] = {"Saturday",  "Sunday",   "Monday", "Tuesday",
                                     "Wednesday", "Thursday", "Friday"};
  
  static string ZellerCongruence(ulong day, ulong month, ulong year) {
    if (month == 1) {
      month = 13;
      year = year - 1;
    } else if (month == 2) {
      month = 14;
      year = year - 1;
    }
    ulong forDay = day, 
          forMonth = month, 
          forYearK = year % 100,
          forYearJ = year / 100;
    ulong newDate = forDay + 13 * (forMonth + 1) / 5 + forYearK + forYearK / 4 +
                    forYearJ / 4 + 5 * forYearJ;
    newDate = newDate % 7;
  
    return callings[newDate];
  }
} // namespace applied