// Demo.h
// use !ONLY! for testing of the program's work
// for version 1.32.X
#pragma once

#include <iostream>

//-------------------------------------

#include "Meeus.h"
#include "MeeusJonesButcher.h"

#include "ZellerCongruence.h"

//-------------------------------------

void testDays(int year) {
  unsigned long *date;
  
  date = applied::MeeusOrthodoxEaster(year);
  std::cout << applied::ZellerDayOfDate(date) << "*\n";
  
  date = applied::MeeusOrthodoxJulianEaster(year);
  std::cout << applied::ZellerDayOfDate(date) << "\n";
  
  date = applied::MJBCatholicEaster(year);
  std::cout << applied::ZellerDayOfDate(date) << "\n";

  std::cout << "* Gregorian calendar does not correlate with Julian" << "\n";
}

void testDate(int day, int month, int year) {
  std::cout << applied::ZellerDayOfDate(day, month, year) << "\n";
}