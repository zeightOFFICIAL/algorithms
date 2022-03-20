#include <iostream>
#include <string>
#include <bitset>
#include "zhf1.h"

using std::string, std::bitset;

ZHF1::ZHF1() {}
ZHF1::~ZHF1() {}

void ZHF1::push_string(const string &string)
{
    for (std::size_t i = 0; i < string.size(); ++i)
        std::cout << bitset<8>(string.c_str()[i]) << "\n";
    
}

string zhf1(const string &string)
{
    ZHF1 hash;
    hash.push_string(string);
    //return hash.pop_result();
    return string;
    
}