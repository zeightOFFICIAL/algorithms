#include <string>
#include <cstdint>
#include <bitset>
#include <algorithm>  

#include "bitwise_operations.h"

using std::string, std::bitset;

string bitwise_not(string s1)
{
    string res;
    for (int i = 0; i < s1.length();i++) {
            if (s1[i]=='0')
                res = res + '1';
            else if (s1[i]=='1')
                res = res + '0';
        }
    return res;
}

string bitwise_and(string s1, string s2)
{
    int length = s1.length();
    string res = "";
    for (int i = 0; i < length; i++) {
        if (s1[i]=='1' && s2[i]=='1')
            res = res + '1';
        else
            res = res + '0';
    }
    //res.erase(0, res.find_first_not_of('0'));
    return res;
}

string bitwise__or(string s1, string s2)
{
    int length = s1.length();
    string res = "";
    for (int i = 0 ; i<length; i++) {
        if ((s1[i] == '1') or (s2[i] == '1'))
            res = res + '1';
        else
            res = res + '0';
        }
    //res.erase(0, res.find_first_not_of('0'));
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
    //res.erase(0, res.find_first_not_of('0'));
    return res;
}

string bitwise_left_rotate(string a, int n)
{
    string res = a;
    //for (int i = a.length(); i < (a.length()+n); i++)
    //    res = res + '0';
    //string res = a;
    //res.insert(res.begin(), res[n-1]);
    //res.erase(res.end() - 1);
    //res.erase(0, res.find_first_not_of('0'));
    std::rotate(res.begin(), res.begin() + n, res.end());
    //res.erase(0, res.find_first_not_of('0'));
    return res;
}

string bitwise_add(string a, string b)
{
    string res = "";
    bitset<32> ba(a);
    bitset<32> bb(b);
    bitset<32> br(bitsetAdd(ba,bb));
    res = br.to_string();
    return res;
}        

bool fullAdder(bool b1, bool b2, bool& carry)
{
    bool sum = (b1 ^ b2) ^ carry;
    carry = (b1 && b2) || (b1 && carry) || (b2 && carry);
    return sum;
}
// Function to add two bitsets
bitset<32> bitsetAdd(bitset<32>& x, bitset<32>& y)
{
    bool carry = false;
    // bitset to store the sum of the two bitsets
    bitset<32> ans;
    for (int i = 0; i < 32; i++) {
        ans[i] = fullAdder(x[i], y[i], carry);
    }
    return ans;
}