// Meeus.h

#include "_Utils.h"

namespace easterday {
  /**
  (unsigned long A) -> (string B)
  Finds date B of the Easter day in year A.
  Uses Meeus algorithm to find Julian Orthodox
  day of Easter. Returns day B.
  */
  static string MeeusJulianEaster(ulong year);
  /**
  (unsigned long A) -> (string B)
  Finds date B of the Easter day in year A.
  Uses Meeus algorithm to find Gregorian Orthodox
  day of Easter. Returns day B.
  ! WORKS ONLY WITHIN 1901..2099 !
  */
  static string MeeusGregorianEaster(ulong year);

  static string MeeusJulianEaster(ulong year) {
    ulong newYear4 = year % 4, 
          newYear7 = year % 7, 
          newYear19 = year % 19;
    ulong d = (19 * newYear19 + 15) % 30,
          e = (2 * newYear4 + 4 * newYear7 - d + 34) % 7;
    e = d + e + 114;
    ulong newMonth = (e / 31), 
          newDay = ((e % 31) + 1);
  
    return std::to_string(newDay) + " " + monthCalling[newMonth - 1] + " " + std::to_string(year);
  }

  static string MeeusGregorianEaster(ulong year) {
    if (year < 1900 || year > 2099) {
      return "Cannot be found";
    }
    
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
  
    return std::to_string(newDay) + " " + monthCalling[newMonth - 1] + " " + std::to_string(year);
  }
} // namespace applied