#include <string>
#include <algorithm>
#include <bitset>
#include <vector>
#include <sstream>

//delete after test -----------------
#include <iostream>
//-----------------------------------

#include "md5.h"
#include "../tools/bitwise_operations.h"

using std::string, std::reverse, std::bitset, std::vector, std::cout;

MD5::MD5()
{
    digest.clear();
    digest.push_back(0x67452301);
	digest.push_back(0xefcdab89);
	digest.push_back(0x98badcfe);
	digest.push_back(0x10325476);
    chunks_bin.clear();
}

void MD5::update(const string &message)  {
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
    chunks_bin = SplitToChuns(message_bin);
}

string MD5::PadMessageBin(string &message_binary)
{
    while (message_binary.length() % 512 != 448)
        message_binary = message_binary + '0';
    return message_binary;
}

string MD5::PadLengthBin(string &length_binary)
{
    while (length_binary.length() != 64)
        length_binary = '0' + length_binary;
    return length_binary;
}

vector<uint32_t> MD5::SplitToChuns(string &message_binary)
{
    vector<uint32_t> chunks;
    string this_part_of_message = "";
    int large_chunk_length = 512, small_chunk_length = 32;
    
    for (auto letter_pos = 0; letter_pos < large_chunk_length; letter_pos++) {
        this_part_of_message = this_part_of_message + message_binary[letter_pos];
            if ((letter_pos+1)%small_chunk_length == 0 && letter_pos+1 > 1)  {
                chunks.push_back(ConvertStrUint(this_part_of_message));
                this_part_of_message = "";
                }
        }
    return chunks;
}

string MD5::final()
{
    string hash = "";
    string A = ConvertUintStr(digest[0]);
    string B = ConvertUintStr(digest[1]);
    string C = ConvertUintStr(digest[2]);
    string D = ConvertUintStr(digest[3]);
    for (int this_rotation = 0; this_rotation < 64; this_rotation++)
        {
            string F;
            int g;
            if (this_rotation < 16)
                {
                    //F = (B & C) | ((~B) & D);
                    const string BandC = BitwiseAnd(B,C);
                    const string notB = BitwiseNot(B);
                    const string BandD = BitwiseAnd(notB,D);
                    F = BitwiseOr(BandC,BandD);
                    g = this_rotation;
                }
            else if (this_rotation < 32)
                {
                    //F = (D & B) | ((~D) & C);
                    const string DandB = BitwiseAnd(D,B);
                    const string notD = BitwiseNot(D);
                    const string DandC = BitwiseAnd(D,C);
                    F = BitwiseOr(DandB,DandC);
                    g = (5*this_rotation+1)%16;
                }
            else if (this_rotation < 48)
                {
                    //F = B ^ C ^ D;
                    const string BxorC = BitwiseXor(B,C);
                    F = BitwiseXor(BxorC,D);
                    g = (3*this_rotation+5)%16;
                }
            else
                {
                    //F = C ^ (B | (~D));
                    const string notD = BitwiseNot(D);
                    const string BorD = BitwiseOr(B,notD);
                    F = BitwiseXor(C,BorD);
                    g = (7*this_rotation)%16;
                }
            //F = F + A + MD5::k[this_rotation] + chunks_bin[g];
            F = BitwiseAdd(F, ConvertUintStr(MD5::k[this_rotation]));
            F = BitwiseAdd(F,A);
            F = BitwiseAdd(F, ConvertUintStr(chunks_bin[g]));
            A = D;
            D = C;
            C = B;
            B = BitwiseAdd(B,BitwiseLRotate(F, MD5::s[this_rotation]));
        }
        digest[0] = digest[0] + ConvertStrUint(A);
        digest[1] = digest[1] + ConvertStrUint(B);
        digest[2] = digest[2] + ConvertStrUint(C);
        digest[3] = digest[3] + ConvertStrUint(D);
    for (int this_string = 0; this_string < 4; this_string++)  {
            bitset<32>this_digest(digest[this_string]);
            //cout<<this_digest<<"\n";
            hash = hash + ConvertBinHex(this_digest.to_string());
        }   
    return hash;    
}

string md5(const string &message)  {
    MD5 checksum;
    checksum.update(message);
    return checksum.final();
}