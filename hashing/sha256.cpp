#include <string>
#include <bitset>
#include <vector>
#include <sstream>

//delete after test -----------------
#include <iostream>
//-----------------------------------

#include "sha256.h"
#include "../tools/bitwise_operations.h"

using std::string, std::bitset, std::cout, std::vector;

SHA256::SHA256()
{
    digest.clear();
    digest.push_back("01101010000010011110011001100111");
	digest.push_back("10111011011001111010111010000101");
	digest.push_back("00111100011011101111001101110010");
	digest.push_back("10100101010011111111010100111010");
	digest.push_back("01010001000011100101001001111111");
	digest.push_back("10011011000001010110100010001100");
	digest.push_back("00011111100000111101100110101011");
	digest.push_back("01011011111000001100110100011001");
    chunks_bin.clear();
}

void SHA256::update(const string &message)
{
    int message_bin_length = message.length()*8;
    string message_bin = "", length_bin = bitset<8>(message_bin_length).to_string();
    for (int i = 0; i < message.length(); ++i) {
        bitset<8> binary_letter(message[i]);
        message_bin = message_bin + binary_letter.to_string();
    }
    message_bin = message_bin + '1';
    message_bin = pad_message_bin(message_bin);
    length_bin = pad_length_bin(length_bin);
    message_bin = message_bin + length_bin;
    chunks_bin = split_to_chunks(message_bin);
}

string SHA256::final() {
    string hash = "";
    uint32_t a = ConvertToUint(digest[0]);
    uint32_t b = ConvertToUint(digest[1]);
    uint32_t c = ConvertToUint(digest[2]);
    uint32_t d = ConvertToUint(digest[3]);
    uint32_t e = ConvertToUint(digest[4]);
    uint32_t f = ConvertToUint(digest[5]);
    uint32_t g = ConvertToUint(digest[6]);
    uint32_t h = ConvertToUint(digest[7]);
    for (int this_rotation = 0; this_rotation < 64; this_rotation++) {
        uint32_t _majority = majority(a,b,c);
        uint32_t xorA = rotr(a,2) ^ rotr(a,13) ^ rotr(a,22);
        uint32_t _choose = choose(e,f,g);
        uint32_t xorE = rotr(e,6) ^ rotr(e,11) ^ rotr(e,25);
        uint32_t sum = ConvertToUint(chunks_bin[this_rotation])+SHA256::k[this_rotation]+h+_choose+xorE;
        uint32_t newA = xorA + _majority + sum;
        uint32_t newE = d + sum;
        h = g;
        g = f;
        f = e;
        e = newE;
		d = c;
        c = b;
        b = a;
        a = newA;
    }
    digest[0] = bitwise_add(digest[0],ConvertToStr(a)).substr(0,32);
    digest[1] = bitwise_add(digest[1],ConvertToStr(b)).substr(0,32);
    digest[2] = bitwise_add(digest[2],ConvertToStr(c)).substr(0,32);
    digest[3] = bitwise_add(digest[3],ConvertToStr(d)).substr(0,32);
    digest[4] = bitwise_add(digest[4],ConvertToStr(e)).substr(0,32);
    digest[5] = bitwise_add(digest[5],ConvertToStr(f)).substr(0,32);
    digest[6] = bitwise_add(digest[6],ConvertToStr(g)).substr(0,32);
    digest[7] = bitwise_add(digest[7],ConvertToStr(h)).substr(0,32);
    for (int this_string = 0; this_string < 8; this_string++)
            hash = hash + convert_bin_to_hex(digest[this_string]);    
    return hash;
}

string SHA256::pad_message_bin(string &message_bin)
{
    while (message_bin.length() % 512 != 448)
        message_bin = message_bin + '0';
    return message_bin;
}

string SHA256::pad_length_bin(string &length_bin)
{
    while (length_bin.length() != 64)
        length_bin = '0' + length_bin;
    return length_bin;
}

vector<string> SHA256::split_to_chunks(string &message_bin)
{
    vector<string> small_chunks_bin;
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

vector<string> SHA256::extend_chunks(vector<string> &chunks_bin)
{
    for (int chunk_number = 16; chunk_number < 64; chunk_number++)
        {
            uint32_t w_15 = ConvertToUint(chunks_bin[chunk_number-15]);
            uint32_t w_2 = ConvertToUint(chunks_bin[chunk_number-2]);
            uint32_t w_7 = ConvertToUint(chunks_bin[chunk_number-7]);
            uint32_t w_16 = ConvertToUint(chunks_bin[chunk_number-16]);
            uint32_t current_w = sig1(w_2) + w_7 + sig0(w_15) + w_16;
            chunks_bin.push_back(ConvertToStr(current_w));
        }
    return chunks_bin;
}

uint32_t ConvertToUint(string s)
{
    uint32_t res;
    bitset<32>bitset_s(s);
    res = bitset_s.to_ulong();
    return res;
}

string ConvertToStr(uint32_t i) 
{
    return bitset<32>(i).to_string();
}
        
uint32_t sig0(uint32_t x) {
	return rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3);
}

uint32_t sig1(uint32_t x) {
	return rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10);
}

uint32_t rotr(uint32_t x, uint32_t n) {
	return (x >> n) | (x << (32 - n));
}

uint32_t choose(uint32_t e, uint32_t f, uint32_t g) {
	return (e & f) ^ (~e & g);
}

uint32_t majority(uint32_t a, uint32_t b, uint32_t c) {
	return (a & (b | c)) | (b & c);
}

string sha256(const string &message)  {
    SHA256 checksum;
    checksum.update(message);
    return checksum.final();
}