// Demo.h
// use !ONLY! for testing of the program's work
// for version 1.32
#pragma once

#include "math.h"
#include <iostream>
#include <chrono>

#include "adler32.h"
#include "fnv.h"
#include "sha1.h"
#include "sha2.h"
#include "fletcher.h"

void testHashing(std::string data = "hello world") {
  typedef std::chrono::steady_clock::time_point timePt;
  timePt b1, e1, b2, e2, b3, e3, b4, e4, b5, e5, b6, e6, b7, e7;
  
  std::cout << "Message: " << data << "\n";

  b1 = std::chrono::steady_clock::now();
  auto s1 = hashing::fnv132(data);
  e1 = std::chrono::steady_clock::now();

  b2 = std::chrono::steady_clock::now();
  auto s2 = hashing::fnv164(data);
  e2 = std::chrono::steady_clock::now();

  b3 = std::chrono::steady_clock::now();
  auto s3 = hashing::adler32(data);
  e3 = std::chrono::steady_clock::now();

  b4 = std::chrono::steady_clock::now();
  auto s4 = hashing::sha1(data);
  e4 = std::chrono::steady_clock::now();

  b5 = std::chrono::steady_clock::now();
  auto s5 = hashing::sha256(data);
  e5 = std::chrono::steady_clock::now();

  b6 = std::chrono::steady_clock::now();
  auto s6 = hashing::fletcher16(data);
  e6 = std::chrono::steady_clock::now(); 

  b7 = std::chrono::steady_clock::now();
  auto s7 = hashing::fletcher32(data);
  e7 = std::chrono::steady_clock::now(); 

  std::cout << "FNV132      " << s1 << " sec: " << (std::chrono::duration_cast<std::chrono::microseconds>(e1 - b1).count()) /1000000.0 << "\n";
  std::cout << "FNV164      " << s2 << " sec: " << (std::chrono::duration_cast<std::chrono::microseconds>(e2 - b2).count()) /1000000.0 << "\n";
  std::cout << "ADLER32     " << s3 << " sec: " << (std::chrono::duration_cast<std::chrono::microseconds>(e3 - b3).count()) /1000000.0 << "\n";
  std::cout << "SHA1        " << s4 << " sec: " << (std::chrono::duration_cast<std::chrono::microseconds>(e4 - b4).count()) /1000000.0 << "\n";
  std::cout << "SHA256      " << s5 << " sec: " << (std::chrono::duration_cast<std::chrono::microseconds>(e5 - b5).count()) /1000000.0 << "\n";
  std::cout << "FLETCHER16  " << s6 << " sec: " << (std::chrono::duration_cast<std::chrono::microseconds>(e6 - b6).count()) /1000000.0 << "\n";
  std::cout << "FLETCHER32  " << s7 << " sec: " << (std::chrono::duration_cast<std::chrono::microseconds>(e7 - b7).count()) /1000000.0 << "\n";

}