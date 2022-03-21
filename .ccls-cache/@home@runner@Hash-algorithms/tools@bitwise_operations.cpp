#include <string>
#include <cstdint>
#include <bitset>
#include <algorithm>  

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
    
string bitwise_xor(string s1, string s2)
{
    string res;
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

string bitwise_add(string a, string b)
{
    string res = "";
    bitset<32> bitset_a(a);
    bitset<32> bitset_b(b);
    bitset<32> bitset_result(bitset_add(bitset_a,bitset_b));
    res = bitset_result.to_string();
    return res;
}        

bool bool_full_adder(bool b1, bool b2, bool& carry)
{
    bool sum = (b1 ^ b2) ^ carry;
    carry = (b1 && b2) || (b1 && carry) || (b2 && carry);
    return sum;
}

bitset<32> bitset_add(bitset<32>& bitset_x, bitset<32>& bitset_y)
{
    bool carry = false;
    bitset<32> res;
    for (int i = 0; i < 32; i++) {
        res[i] = bool_full_adder(bitset_x[i], bitset_y[i], carry);
    }
    return res;
}