#include <string>
#include <algorithm>
#include <bitset>
#include <vector>
#include <cstdint>

//------------------- delete after test
#include <iostream>
//-------------------------------------

#include "sagh.h"

using std::string, std::reverse, std::cout, std::bitset, std::vector;

SAGH::SAGH() {
    digest.clear();
    digest.push_back("01100111010001010010001100000001");
    digest.push_back("11101111110011011010101110001001");
    digest.push_back("10011000101110101101110011111110");
    digest.push_back("00010000001100100101010001110110");
    digest.push_back("11000011110100101110000111110000");
    chunks_bin.clear();
}

void SAGH::update(const string &message)  {
    int n = message.length();
    int message_bin_length = (n)*8;
    string message_bin_length_bin = bitset<8>(message_bin_length).to_string();
    string message_bin = "", length_bin = "";
    
    for (int i = 0; i <= n-1; i++)  {
        int val = int(message[i]);
        string letter_bin = "";
        while (val > 0) {
            (val % 2)? letter_bin.push_back('1') :
                       letter_bin.push_back('0');
            val /= 2;
        }
        reverse(letter_bin.begin(), letter_bin.end());
        while (letter_bin.length()<8)
            letter_bin = '0'+letter_bin;
        message_bin = message_bin + letter_bin;
    }
    message_bin = message_bin + '1';
    length_bin = SAGH::pad_length_bin(message_bin_length_bin);
    message_bin = SAGH::pad(message_bin);
    message_bin = message_bin + length_bin;
    chunks_bin = SAGH::cut_bin(message_bin);
}

std::string SAGH::final()
{
    string hash = "";
    string a = digest[0];
    string b = digest[1];
    string c = digest[3];
    string d = digest[4];
    string e = digest[5]; 
            for (int this_rotation = 0; this_rotation < 80; this_rotation++)  {  
                string f,k;
                    if (this_rotation < 20)  {
                        const string BandC = bitwise_and(b,c);
                        const string notB = bitwise_and(bitwise_not(b),d);
                        f = bitwise_or(BandC, notB);
                        k = "01011010100000100111100110011001";
                    }
                    else if (this_rotation < 40) {
                        const string BxorC = bitwise_xor(b,c);
                        f = bitwise_xor(BxorC, d);
                        k = "01101110110110011110101110100001";
                    }
                    else if (this_rotation < 60) {
                        const string BandC = bitwise_and(b,c);
                        const string BandD = bitwise_and(b,d);
                        const string CandD = bitwise_and(c,d);
                        const string BandCorBandD = bitwise_or(BandC,BandD);
                        f = bitwise_or(BandCorBandD,CandD);
                        k = "10001111000110111011110011011100";
                    }
                    else  {
                        const string BxorC = bitwise_xor(b,c);
                        f = bitwise_xor(BxorC, d);
                        k = "11001010011000101100000111010110";
                    }
                    const string chunk = chunks_bin[this_rotation];
                    const string tempA = addBinary(left_rotate(a,5),f);
                    const string tempB = addBinary(tempA, e);
                    const string tempC = addBinary(tempB, k);
                    string temp = addBinary(tempC,chunk);

                    temp = temp.substr(0,32);
                    e = d;
                    d = c;
                    c = left_rotate(b,30);
                    b = a;
                    a = temp;
                }
            digest[0] = addBinary(digest[0],a).substr(0,32);
            digest[1] = addBinary(digest[1],b).substr(0,32);
            digest[2] = addBinary(digest[2],c).substr(0,32);
            digest[3] = addBinary(digest[3],d).substr(0,32);
            digest[4] = addBinary(digest[4],e).substr(0,32);
    for (int h = 0; h < 5; h++)
        cout<<digest[h]<<"\n";
    
    hash = digest[0]+digest[1]+digest[2]+digest[3]+digest[4];
    return hash;
}

string SAGH::pad(string &message_bin)
{
    while (message_bin.length() % 512 != 448)
        message_bin = message_bin + '0';
    return message_bin;
}

string SAGH::pad_length_bin(string &length_bin)
{
    while (length_bin.length() != 64)
        length_bin = '0' + length_bin;
    return length_bin;
}

vector<string> SAGH::cut_bin(string &message_bin)
{
    vector<string> large_chunks_bin, small_chunks_bin;
    string this_part_of_message = "";
    int large_chunk_length = 512, small_chunk_length = 32;
    
    for (auto letter_pos = 0; letter_pos < large_chunk_length; letter_pos++)
        {
            this_part_of_message = this_part_of_message + message_bin[letter_pos];
            if ((letter_pos+1)%small_chunk_length == 0 && letter_pos+1 > 1)  {
                small_chunks_bin.push_back(this_part_of_message);
                this_part_of_message = "";
            }
        }
    small_chunks_bin = SAGH::extend_chunks(small_chunks_bin);
    return small_chunks_bin;
}

vector<string> SAGH::extend_chunks(vector<string> &chunks_bin)
{
    for (auto chunk_number = 16; chunk_number < 80; chunk_number++)
        {
            const string wordA = chunks_bin[chunk_number-3];
            const string wordB = chunks_bin[chunk_number-8];
            const string wordC = chunks_bin[chunk_number-14];
            const string wordD = chunks_bin[chunk_number-16];

            const string xorA = bitwise_xor(wordA, wordB); 
            const string xorB = bitwise_xor(xorA, wordC);
            const string xorC = bitwise_xor(xorB, wordD);

            string newchunk;
            newchunk = left_rotate(xorC,1);
            chunks_bin.push_back(newchunk);
        }
    return chunks_bin;
}

string bitwise_not(string s1)
{
    string res;
    for (int i = 0; i < s1.length();i++) {
            if (s1[i]=='0')
                res = res + '1';
            else if (s1[i]=='1')
                res = res + '0';
        }
    res.erase(0, res.find_first_not_of('0'));
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
    res.erase(0, res.find_first_not_of('0'));
    return res;
}

string bitwise_or(string s1, string s2)
{
    int length = s1.length();
    string res = "";
    for (int i = 0 ; i<length; i++) {
        if ((s1[i] == '1') or (s2[i] == '1'))
            res = res + '1';
        else
            res = res + '0';
        }
    res.erase(0, res.find_first_not_of('0'));
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
    res.erase(0, res.find_first_not_of('0'));
    return res;
}

string left_rotate(string a, int n)
{
    string res = a;
    //for (int i = a.length(); i < (a.length()+n); i++)
    //    res = res + '0';
    //string res = a;
    res.insert(res.begin(), res[n - 1]);
    res.erase(res.end() - 1);
    res.erase(0, res.find_first_not_of('0'));
    //res.erase(0, res.find_first_not_of('0'));
    return res;
}

string addBinary(string A, string B)
{
    if (A.length() > B.length())
        return addBinary(B, A);
    int diff = B.length() - A.length();
    string padding;
    for (int i = 0; i < diff; i++)
        padding.push_back('0');
    A = padding + A;
    string res;
    char carry = '0';
    for (int i = A.length() - 1; i >= 0; i--) {
        if (A[i] == '1' && B[i] == '1') {
            if (carry == '1')
                res.push_back('1'), carry = '1';
            else
                res.push_back('0'), carry = '1';
        }
        else if (A[i] == '0' && B[i] == '0') {
            if (carry == '1')
                res.push_back('1'), carry = '0';
            else
                res.push_back('0'), carry = '0';
        }
        else if (A[i] != B[i]) {
            if (carry == '1')
                res.push_back('0'), carry = '1';
            else
                res.push_back('1'), carry = '0';
        }
    }
    if (carry == '1')
        res.push_back(carry);
    reverse(res.begin(), res.end());
    int index = 0;
    while (index + 1 < res.length() && res[index] == '0')
        index++;
    res.erase(0, res.find_first_not_of('0'));
    return (res.substr(index));
}        

string sagh(const string &message)  {
    SAGH checksum;
    checksum.update(message);
    return checksum.final();
}