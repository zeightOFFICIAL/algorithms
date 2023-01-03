// GaussEaster.h

#include <string>
#include "_Utils.h"

namespace easterday {
  /**
  (ulong A) -> (string B)
  Finds date B of the easter day in year A.
  Uses Anonymous algorithm to find Gregorian
  day of easter. Returns day B.
  */
  static string GaussGregorianEaster(ulong year) {
    ulong newDay, newMonth;
    
    double newYear19 = year % 19,
          newYear4  = year % 4,
          newYear7  = year % 7,
          newYear100= year % 100;
    double p = (13 + 8 * newYear100) / 25,
          q = newYear100 / 4,
          m = (15 - p + newYear100 - q) % 30,
          n = (4 + newYear100 - q) % 7,
          d = (19 * newYear19 + m),
          e = (2 * newYear4 + 4 * newYear7 + 6 * d + n) % 7;
    double march = 22 + d + e;
    double april = d + e - 9;

    if (d == 28 & e == 6 & ((11 * m + 11) % 30) < 19) {
      newDay = 18;
      newMonth = 3;
    }
    else if (d == 29 & e == 6) {
      newDay = 19;
      newMonth = 3;
    }
    else {
      newMonth = m;
      newDay = d;
    }
  
    return std::to_string(newDay) + " " + monthName[newMonth - 1] + " " + std::to_string(year);
  }
} // namespace applied