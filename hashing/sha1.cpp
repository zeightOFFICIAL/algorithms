#include <string>
#include <algorithm>
#include <bitset>
#include <vector>
#include <sstream>

#include "sha1.h"
#include "../tools/bitwise_operations.h"

using std::string, std::reverse, std::bitset, std::vector;

SHA1::SHA1() {
    digest.clear();
    digest.push_back("01100111010001010010001100000001");
    digest.push_back("11101111110011011010101110001001");
    digest.push_back("10011000101110101101110011111110");
    digest.push_back("00010000001100100101010001110110");
    digest.push_back("11000011110100101110000111110000");
    chunks_bin.clear();
}

void SHA1::update(const string &message)  {
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
    length_bin = pad_length_bin(message_bin_length_bin);
    message_bin = pad_message_bin(message_bin);
    message_bin = message_bin + length_bin;
    chunks_bin = split_to_chunks(message_bin);
}

std::string SHA1::final()
{
    string hash = "";
    string a = digest[0];
    string b = digest[1];
    string c = digest[2];
    string d = digest[3];
    string e = digest[4]; 
            for (int this_rotation = 0; this_rotation < 80; this_rotation++)  {  
                string f,k;
                    if (this_rotation < 20)  {
                        const string BandC = bitwise_and(b,c);
                        const string notB = bitwise_and(bitwise_not(b),d);
                        f = bitwise__or(BandC, notB);
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
                        const string BandCorBandD = bitwise__or(BandC,BandD);
                        f = bitwise__or(BandCorBandD,CandD);
                        k = "10001111000110111011110011011100";
                    }
                    else  {
                        const string BxorC = bitwise_xor(b,c);
                        f = bitwise_xor(BxorC, d);
                        k = "11001010011000101100000111010110";
                    }
                    const string chunk = chunks_bin[this_rotation];
                    const string tempA = bitwise_add(bitwise_left_rotate(a,5),f);
                    const string tempB = bitwise_add(tempA, e);
                    const string tempC = bitwise_add(tempB, k);
                    string temp = bitwise_add(tempC,chunk);

                    temp = temp.substr(0,32);
                    e = d;
                    d = c;
                    c = bitwise_left_rotate(b,30);
                    b = a;
                    a = temp;
                }
            digest[0] = bitwise_add(digest[0],a).substr(0,32);
            digest[1] = bitwise_add(digest[1],b).substr(0,32);
            digest[2] = bitwise_add(digest[2],c).substr(0,32);
            digest[3] = bitwise_add(digest[3],d).substr(0,32);
            digest[4] = bitwise_add(digest[4],e).substr(0,32);

    for (int this_string = 0; this_string < 5; this_string++)
            hash = hash + convert_bin_to_hex(digest[this_string]);

    return hash;
}

string SHA1::pad_message_bin(string &message_bin)
{
    while (message_bin.length() % 512 != 448)
        message_bin = message_bin + '0';
    return message_bin;
}

string SHA1::pad_length_bin(string &length_bin)
{
    while (length_bin.length() != 64)
        length_bin = '0' + length_bin;
    return length_bin;
}

vector<string> SHA1::split_to_chunks(string &message_bin)
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
    small_chunks_bin = extend_chunks(small_chunks_bin);
    return small_chunks_bin;
}

vector<string> SHA1::extend_chunks(vector<string> &chunks_bin)
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
            newchunk = bitwise_left_rotate(xorC,1);
            chunks_bin.push_back(newchunk);
        }
    return chunks_bin;
}

string sha1(const string &message)  {
    SHA1 checksum;
    checksum.update(message);
    return checksum.final();
}