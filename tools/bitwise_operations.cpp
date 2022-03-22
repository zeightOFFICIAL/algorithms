#include <string>
#include <cstdint>
#include <bitset>
#include <algorithm>  
#include <sstream>

#include "bitwise_operations.h"

using std::string, std::bitset, std::rotate;

string BitwiseNot(string s1)  {
    string res;
    
    for (int i = 0; i < s1.length();i++)  {
            if (s1[i]=='0')
                res = res + '1';
            else if (s1[i]=='1')
                res = res + '0';
        }
    return res;
}

string BitwiseAnd(string s1, string s2)  {
    string res = "";

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i]=='1' && s2[i]=='1')
            res = res + '1';
        else
            res = res + '0';
    }
    return res;
}

string BitwiseOr(string s1, string s2)  {
    string res = "";
    
    for (int i = 0 ; i < s1.length(); i++) {
        if ((s1[i] == '1') or (s2[i] == '1'))
            res = res + '1';
        else
            res = res + '0';
        }
    return res;
}
    
string BitwiseXor(string s1, string s2)  {
    string res = "";
    
    for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i]==s2[i])
                res = res+"0";
            else
                res = res+"1";
        }
    return res;
}

string BitwiseLRotate(string s1, int size_of_rotate)
{
    string res = s1;
    rotate(res.begin(), res.begin() + size_of_rotate, res.end());
    return res;
}

string BitwiseAdd(string s1, string s2)
{
    string res = "";
    bitset<32> bitset_a(s1);
    bitset<32> bitset_b(s2);
    bitset<32> bitset_result(BitsetAdd(bitset_a,bitset_b));
    res = bitset_result.to_string();
    return res;
}        

bool BoolFullAdd(bool b1, bool b2, bool& carry_over)
{
    bool sum = (b1 ^ b2) ^ carry_over;
    carry_over = (b1 && b2) || (b1 && carry_over) || (b2 && carry_over);
    return sum;
}

bitset<32> BitsetAdd(bitset<32>& bitset_x, bitset<32>& bitset_y)
{
    bool carry_over = false;
    bitset<32> res;
    for (int i = 0; i < 32; i++) {
        res[i] = BoolFullAdd(bitset_x[i], bitset_y[i], carry_over);
    }
    return res;
}

string ConvertBinHex(string bin)  {
    bitset<32> set(bin);
    std::stringstream res;
    res << std::hex << set.to_ulong();
    return res.str();
}

uint32_t ConvertStrUint(string str)  {
    return bitset<32>(str).to_ulong();
}

string ConvertUintStr(uint32_t uint)  {
    return bitset<32>(uint).to_string();
}
        
uint32_t Sigma0(uint32_t x) {
	return RotateRight(x, 7) ^ RotateRight(x, 18) ^ (x >> 3);
}

uint32_t Sigma1(uint32_t x) {
	return RotateRight(x, 17) ^ RotateRight(x, 19) ^ (x >> 10);
}

uint32_t RotateRight(uint32_t x, uint32_t n) {
	return (x >> n) | (x << (32 - n));
}

uint32_t RotateLeft(uint32_t x, uint32_t n) {
	return (x << n) | (x >> (32 - n));
}

uint32_t Choose(uint32_t e, uint32_t f, uint32_t g) {
	return (e & f) ^ (~e & g);
}

uint32_t Majority(uint32_t a, uint32_t b, uint32_t c) {
	return (a & (b | c)) | (b & c);
}        