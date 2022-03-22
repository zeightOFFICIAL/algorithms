#include <string>
#include <cstdint>
#include <bitset>
#include <algorithm>  
#include <sstream>

#include "bitwise_operations.h"

using std::string, std::bitset, std::rotate;

string bitwise_not(string s1)  {
    string res;
    
    for (int i = 0; i < s1.length();i++)  {
            if (s1[i]=='0')
                res = res + '1';
            else if (s1[i]=='1')
                res = res + '0';
        }
    return res;
}

string bitwise_and(string s1, string s2)  {
    string res = "";

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i]=='1' && s2[i]=='1')
            res = res + '1';
        else
            res = res + '0';
    }
    return res;
}

string bitwise__or(string s1, string s2)  {
    string res = "";
    
    for (int i = 0 ; i < s1.length(); i++) {
        if ((s1[i] == '1') or (s2[i] == '1'))
            res = res + '1';
        else
            res = res + '0';
        }
    return res;
}
    
string bitwise_xor(string s1, string s2)  {
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

string bitwise_left_rotate(string s1, int size_of_shift)
{
    string res = s1;
    rotate(res.begin(), res.begin() + size_of_shift, res.end());
    return res;
}

string bitwise_right_rotate(string s1, int size_of_shift)
{
    string res = s1;
    rotate(res.rbegin(), res.rbegin() + size_of_shift, res.rend());
    return res;
}

string bitwise_right_shift(string s1, int size_of_shift)
{
    bitset<32>bitset_s1(s1);
    bitset_s1 = bitset_s1 >> size_of_shift;
    string res = bitset_s1.to_string();
    res.erase(0, res.find_first_not_of('0'));
    return res;
}

string bitwise_add(string a, string b)
{
    string res = "";
    bitset<32> bitset_a(a);
    bitset<32> bitset_b(b);
    bitset<32> bitset_result(bitset_add(bitset_a,bitset_b));
    res = bitset_result.to_string();
    return res;
}        

bool bool_full_adder(bool b1, bool b2, bool& carry_over)
{
    bool sum = (b1 ^ b2) ^ carry_over;
    carry_over = (b1 && b2) || (b1 && carry_over) || (b2 && carry_over);
    return sum;
}

bitset<32> bitset_add(bitset<32>& bitset_x, bitset<32>& bitset_y)
{
    bool carry_over = false;
    bitset<32> res;
    for (int i = 0; i < 32; i++) {
        res[i] = bool_full_adder(bitset_x[i], bitset_y[i], carry_over);
    }
    return res;
}

bitset<32> bit_wise_sigma0(string ch1)
{
    bitset<32>bitset_ch1(bitwise_right_rotate(ch1,7)), bitset_ch2(bitwise_right_rotate(ch1,18)), bitset_ch3(ch1);
    bitset_ch3 = bitset_ch3 >> 3;
    bitset<32>sig0 = bitset_ch1 ^ bitset_ch2 ^ bitset_ch3;
    return sig0;
}

bitset<32> bit_wise_sigma1(string ch1)
{
    bitset<32>bitset_ch1(bitwise_right_rotate(ch1,17)), bitset_ch2(bitwise_right_rotate(ch1,19)), bitset_ch3(ch1);
    bitset_ch3 = bitset_ch3 >> 10;
    
    bitset<32>sig1 = bitset_ch1 ^ bitset_ch2 ^ bitset_ch3;
    return sig1;
}

string convert_bin_to_hex(string bin)
{
    bitset<32> set(bin);
    std::stringstream res;
    res << std::hex << set.to_ulong();
    return res.str();
}