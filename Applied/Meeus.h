/*
Zeight Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Meeus.h

namespace applied {
  typedef unsigned long ulong;
  /**
  (unsigned long A) -> (unsigned long[3] B)
  Finds date B of the Easter day in year A.
  Uses Meeus algorithm to find Orthodox
  day of Easter. Returns day B.
  B = [
        unsigned long DAY, 
        unsigned long MONTH, 
        unsigned long YEAR
      ]
  */
  static ulong* MeeusOrthodoxEaster(ulong year);
  /**
  (unsigned long A) -> (unsigned long[3] B)
  Finds date B of the Easter day in year A.
  Uses Meeus algorithm to find Orthodox Gregorian
  day of Easter. Returns day B.
  B = [
        unsigned long DAY, 
        unsigned long MONTH, 
        unsigned long YEAR
      ]
  ! WORKS ONLY WITHIN 1901..2099 !
  */
  static ulong* MeeusOrthodoxJulianEaster(ulong year);

  static ulong* MeeusOrthodoxEaster(ulong year) {
    ulong D, M;
    ulong a = year % 4, 
    b = year % 7, 
    c = year % 19,
    d = (19 * c + 15) % 30,
    e = (2 * a + 4 * b - d + 34) % 7;  
    
    e = d + e + 114;    
    M = (e / 31);
    D = ((e % 31) + 1);
  
    static ulong date[3] = {D, M, year};
    return date;
  }

  static ulong* MeeusOrthodoxJulianEaster(ulong year) {
    ulong D, M;
    ulong a = year % 4, 
    b = year % 7, 
    c = year % 19,
    d = (19 * c + 15) % 30,
    e = (2 * a + 4 * b - d + 34) % 7;    
    
    e = d + e + 114;
    M = (e / 31);
    D = ((e % 31) + 1);
    D = D + 13;    
    if (D > 31 && M == 3) {
      D = D - 31;
      M = M + 1;
    }
    else if (D > 30 && M == 4){
      D = D - 30;
      M = M + 1;
    }

    static ulong date[3] = {D, M, year};
    return date;
  }
} // namespace applied