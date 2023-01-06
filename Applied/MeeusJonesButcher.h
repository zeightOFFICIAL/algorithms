// MeeusJonesButcher.h

#include "_Utils.h"

namespace easterday {
  /**
  (ulong A) -> (string B)
  Finds date B of the easter day in year A.
  Uses Meeus Jones Butcher algorithm to find 
  Catholic Gregorian day of easter. Returns day B.
  */
  static string MJBCatholicEaster(ulong year) {
    ulong a = year % 19,
    b = year / 100,
    c = year % 100,
    d = b / 4,
    e = b % 4,
    g = (8 * b + 13) / 25,
    h = (19 * a + b - d - g + 15) % 30,
    i = c / 4,
    k = c % 4,
    I = (32 + 2 * e + 2 * i - h - k) % 7,
    m = (a + 11 * h + 19 * I) / 433,
    n = (h + I - 7 * m + 114) / 31,
    p = (h + I - 7 * m + 33 * n + 19) % 32;
    
    return std::to_string(p) + " " + monthCalling[n - 1] + " " + std::to_string(year);
  }
} // namespace applied