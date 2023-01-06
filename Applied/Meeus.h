// Meeus.h

#include "_Utils.h"

namespace easterday {
  /**
  (unsigned long A) -> (string B)
  Finds date B of the Easter day in year A.
  Uses Meeus algorithm to find Orthodox
  day of Easter. Returns day B.
  */
  static string MeeusOrthodoxEaster(ulong year);
  /**
  (unsigned long A) -> (string B)
  Finds date B of the Easter day in year A.
  Uses Meeus algorithm to find Gregorian Orthodox
  day of Easter. Returns day B.
  ! WORKS ONLY WITHIN 1901..2099 !
  */
  static string MeeusOrthodoxJulianEaster(ulong year);

  static string MeeusOrthodoxEaster(ulong year) {
    ulong a = year % 4, 
    b = year % 7, 
    c = year % 19,
    d = (19 * c + 15) % 30,
    e = (2 * a + 4 * b - d + 34) % 7;  
    
    e = d + e + 114;    
    ulong newMonth = (e / 31), 
          newDay = ((e % 31) + 1);
  
    return std::to_string(newDay) + " " + monthCalling[newMonth - 1] + " " + std::to_string(year);
  }

  static string MeeusOrthodoxJulianEaster(ulong year) {   
    ulong newYear4 = year % 4, 
          newYear7 = year % 7, 
          newYear19 = year % 19;
    ulong d = (19 * newYear19 + 15) % 30,
          e = (2 * newYear4 + 4 * newYear7 - d + 34) % 7;
    e = d + e + 114;
    ulong newMonth = (e / 31), 
          newDay = ((e % 31) + 1);
    newDay = newDay + 13;
    if (newDay > 31 && newMonth == 3) {
      newDay = newDay - 31;
      newMonth = newMonth + 1;
    }
    else if (newDay > 30 && newMonth == 4){
      newDay = newDay - 30;
      newMonth = newMonth + 1;
    }

    if (year < 1900 || year > 2099) {
      return "RATHER INCORRECT! " + std::to_string(newDay) + " " + monthCalling[newMonth - 1] + " " + std::to_string(year);
    }
    else {
      return std::to_string(newDay) + " " + monthCalling[newMonth - 1] + " " + std::to_string(year);
    }  
  }
} // namespace applied