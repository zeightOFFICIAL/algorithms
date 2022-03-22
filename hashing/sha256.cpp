#include <string>
#include <bitset>
#include <vector>
#include <sstream>

#include "sha256.h"
#include "../tools/bitwise_operations.h"

using std::string, std::bitset, std::vector;

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
    message_bin = PadMessageBin(message_bin);
    length_bin = PadLengthBin(length_bin);
    message_bin = message_bin + length_bin;
    chunks_bin = SplitToChunks(message_bin);
}

string SHA256::final() {
    string hash = "";
    uint32_t a = ConvertStrUint(digest[0]);
    uint32_t b = ConvertStrUint(digest[1]);
    uint32_t c = ConvertStrUint(digest[2]);
    uint32_t d = ConvertStrUint(digest[3]);
    uint32_t e = ConvertStrUint(digest[4]);
    uint32_t f = ConvertStrUint(digest[5]);
    uint32_t g = ConvertStrUint(digest[6]);
    uint32_t h = ConvertStrUint(digest[7]);
    for (int this_rotation = 0; this_rotation < 64; this_rotation++) {
        uint32_t _majority = Majority(a,b,c);
        uint32_t xorA = RotateRight(a,2) ^ RotateRight(a,13) ^ RotateRight(a,22);
        uint32_t _choose = Choose(e,f,g);
        uint32_t xorE = RotateRight(e,6) ^ RotateRight(e,11) ^ RotateRight(e,25);
        uint32_t sum = ConvertStrUint(chunks_bin[this_rotation])+SHA256::k[this_rotation]+h+_choose+xorE;
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
    digest[0] = BitwiseAdd(digest[0],ConvertUintStr(a)).substr(0,32);
    digest[1] = BitwiseAdd(digest[1],ConvertUintStr(b)).substr(0,32);
    digest[2] = BitwiseAdd(digest[2],ConvertUintStr(c)).substr(0,32);
    digest[3] = BitwiseAdd(digest[3],ConvertUintStr(d)).substr(0,32);
    digest[4] = BitwiseAdd(digest[4],ConvertUintStr(e)).substr(0,32);
    digest[5] = BitwiseAdd(digest[5],ConvertUintStr(f)).substr(0,32);
    digest[6] = BitwiseAdd(digest[6],ConvertUintStr(g)).substr(0,32);
    digest[7] = BitwiseAdd(digest[7],ConvertUintStr(h)).substr(0,32);
    for (int this_string = 0; this_string < 8; this_string++)
            hash = hash + ConvertBinHex(digest[this_string]);    
    return hash;
}

string SHA256::PadMessageBin(string &message_bin)
{
    while (message_bin.length() % 512 != 448)
        message_bin = message_bin + '0';
    return message_bin;
}

string SHA256::PadLengthBin(string &length_bin)
{
    while (length_bin.length() != 64)
        length_bin = '0' + length_bin;
    return length_bin;
}

vector<string> SHA256::SplitToChunks(string &message_bin)
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
    small_chunks_bin = ExtendChunks(small_chunks_bin);
    return small_chunks_bin;
}

vector<string> SHA256::ExtendChunks(vector<string> &chunks_bin)
{
    for (int chunk_number = 16; chunk_number < 64; chunk_number++)
        {
            uint32_t w_15 = ConvertStrUint(chunks_bin[chunk_number-15]);
            uint32_t w_2 = ConvertStrUint(chunks_bin[chunk_number-2]);
            uint32_t w_7 = ConvertStrUint(chunks_bin[chunk_number-7]);
            uint32_t w_16 = ConvertStrUint(chunks_bin[chunk_number-16]);
            uint32_t current_w = Sigma1(w_2) + w_7 + Sigma0(w_15) + w_16;
            chunks_bin.push_back(ConvertUintStr(current_w));
        }
    return chunks_bin;
}

string sha256(const string &message)  {
    SHA256 checksum;
    checksum.update(message);
    return checksum.final();
}