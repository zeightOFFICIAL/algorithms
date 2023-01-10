/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// MeeusJonesButcher.h

namespace applied {
  typedef unsigned long ulong;
  /**
  (unsigned long A) -> (unsigned long[3] B)
  Finds date B of the Easter day in year A.
  Uses Meeus Jones Butcher algorithm to find 
  Catholic Gregorian day of Easter. Returns day B.
  B = [
        unsigned long DAY, 
        unsigned long MONTH, 
        unsigned long YEAR
      ]
  */
  static ulong* MJBCatholicEaster(ulong year);

  static ulong* MJBCatholicEaster(ulong year) {
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
    M = (h + I - 7 * m + 114) / 31,
    D = (h + I - 7 * m + 33 * M + 19) % 32;
    
    static ulong date[3] = {D, M, year};
    return date;
  }
} // namespace applied