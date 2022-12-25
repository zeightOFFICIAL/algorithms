// Demo.h
// use !ONLY! for testing of the program's work
// for version 1.32
#pragma once

#include "math.h"
#include <chrono>
#include <iostream>
#include <iomanip>

#include "BorweinPi.h"
#include "ChudnovskyPi.h"
#include "GaussLegendrePi.h"

#include "KahanSum.h"
#include "NaiveSum.h"

#include "NaiveExp.h"
#include "SquaringExp.h"

void testPi() {
  double tempValue1, tempValue2, tempValue3,
         tempValue4, tempValue5, tempValue6;
  int localPrec;

  for (int localPrec = 1; localPrec < 4; localPrec++) {
    std::cout << localPrec << "\n";

    tempValue1 = picalc::ChudnovskyPi(localPrec);
    tempValue2 = picalc::BorweinQuadratic(localPrec);
    tempValue3 = picalc::GaussLegendrePi(localPrec);
    tempValue4 = picalc::BorweinCubic(localPrec);
    tempValue5 = picalc::BorweinQuartic(localPrec);

    std::cout << std::setprecision(30) << "Math.h PI:     " << M_PI << "\n";
    std::cout << std::setprecision(30) << "BorweinQuadra: " << tempValue2 << "\n";
    std::cout << std::setprecision(30) << "GaussLegendre: " << tempValue3 << "\n";
    std::cout << std::setprecision(30) << "Math.h 1/PI:   " << 1.0/M_PI << "\n";
    std::cout << std::setprecision(30) << "Chudnovsky:    " << tempValue1 << "\n";
    std::cout << std::setprecision(30) << "BorweinCubic:  " << tempValue4 << "\n";
    std::cout << std::setprecision(30) << "BorweinQuarti: " << tempValue5 << "\n";
  }
}

void testExp() {
  
}