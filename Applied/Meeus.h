// Meeus.h

#include <string>
#include "_Utils.h"

namespace easterday {
  /**
  (ulong A) -> (string B)
  Finds date B of the easter day in year A.
  Uses Meeus algorithm to find Julian Orthodox
  day of easter. Returns day B.
  */
  static string MeeusJulianEaster(ulong year) {
    ulong newYear4 = year % 4, 
          newYear7 = year % 7, 
          newYear19 = year % 19;
    ulong d = (19 * newYear19 + 15) % 30,
          e = (2 * newYear4 + 4 * newYear7 - d + 34) % 7;
    e = d + e + 114;
    ulong newMonth = (e / 31), 
          newDay = ((e % 31) + 1);
  
    return std::to_string(newDay) + " " + monthName[newMonth - 1] + " " + std::to_string(year);
  }
} // namespace applied