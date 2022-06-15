#include <string>
#include <algorithm>
#include <bitset>
#include <vector>
#include <sstream>

#include <iostream>

#include "adler32.h"
#include "../tools/bitwise_operations.h"

const uint32_t MOD_ADLER = 65521;

void adler32(std::string data) 
{
    int len = data.length();
    uint32_t a = 1, b = 0;
    std::string hash = "";
    for (size_t index = 0; index < len; ++index)  {
        a = (a + data[index]) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }
    a  = (b << 16) | a;
    hash = ConvertUintStr(a);
    //std::cout << hash;
    return (b << 16) | a;
}