#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <vector>
#include <sstream>

#include "sha1.h"

SHA1::SHA1() {
    chunks.clear();
    digest.clear();
    digest.push_back(0x67452301);
    digest.push_back(0xEFCDAB89);
    digest.push_back(0x98BADCFE);
    digest.push_back(0x10325476);
    digest.push_back(0xC3D2E1F0);
}
SHA1::~SHA1() { }

void SHA1::transform(const std::string message)  {
    int message_length = message.length();
    std::string message_bin = "";
    std::string message_length_bin = std::bitset<8>(message_length).to_string();
    for (size_t letter = 0; letter < message_length; letter++) {
        std::bitset<8> letter_bin = std::bitset<8>(message[letter]);
        message_bin = message_bin + letter_bin.to_string();
    }
    message_bin = message_bin + "1";
    message_bin = message_padding(message_bin);
    message_length_bin = length_bin_padding(message_length_bin);
    message_bin = message_bin + message_length_bin;
    split_to_chunks(message_bin);
}

// std::string SHA1::final()
// {
//     string hash = "";
//     string a = digest[0];
//     string b = digest[1];
//     string c = digest[2];
//     string d = digest[3];
//     string e = digest[4]; 
//             for (int this_rotation = 0; this_rotation < 80; this_rotation++)  {  
//                 string f,k;
//                     if (this_rotation < 20)  {
//                         const string BandC = BitwiseAnd(b,c);
//                         const string notB = BitwiseAnd(BitwiseNot(b),d);
//                         f = BitwiseOr(BandC, notB);
//                         k = "01011010100000100111100110011001";
//                     }
//                     else if (this_rotation < 40) {
//                         const string BxorC = BitwiseXor(b,c);
//                         f = BitwiseXor(BxorC, d);
//                         k = "01101110110110011110101110100001";
//                     }
//                     else if (this_rotation < 60) {
//                         const string BandC = BitwiseAnd(b,c);
//                         const string BandD = BitwiseAnd(b,d);
//                         const string CandD = BitwiseAnd(c,d);
//                         const string BandCorBandD = BitwiseOr(BandC,BandD);
//                         f = BitwiseOr(BandCorBandD,CandD);
//                         k = "10001111000110111011110011011100";
//                     }
//                     else  {
//                         const string BxorC = BitwiseXor(b,c);
//                         f = BitwiseXor(BxorC, d);
//                         k = "11001010011000101100000111010110";
//                     }
//                     const string chunk = chunks_bin[this_rotation];
//                     const string tempA = BitwiseAdd(BitwiseLRotate(a,5),f);
//                     const string tempB = BitwiseAdd(tempA, e);
//                     const string tempC = BitwiseAdd(tempB, k);
//                     string temp = BitwiseAdd(tempC,chunk);

//                     temp = temp.substr(0,32);
//                     e = d;
//                     d = c;
//                     c = BitwiseLRotate(b,30);
//                     b = a;
//                     a = temp;
//                 }
//             digest[0] = BitwiseAdd(digest[0],a).substr(0,32);
//             digest[1] = BitwiseAdd(digest[1],b).substr(0,32);
//             digest[2] = BitwiseAdd(digest[2],c).substr(0,32);
//             digest[3] = BitwiseAdd(digest[3],d).substr(0,32);
//             digest[4] = BitwiseAdd(digest[4],e).substr(0,32);

//     for (int this_string = 0; this_string < 5; this_string++)
//             hash = hash + ConvertBinHex(digest[this_string]);

//     return hash;
// }

std::string SHA1::message_padding(std::string message_bin)
{
    while (message_bin.length() % 512 != 448)
        message_bin = message_bin + '0';
    return message_bin;
}

std::string SHA1::length_bin_padding(std::string length_bin)
{
    while (length_bin.length() != 64)
        length_bin = '0' + length_bin;
    return length_bin;
}

void SHA1::split_to_chunks(std::string message_bin)
{
    int small_chunk_length = 32;
    std::bitset<32> this_chunk;
    for (size_t chunk_index = 0; chunk_index < 16; chunk_index++) {
        this_chunk = std::bitset<32>(message_bin.substr(chunk_index*small_chunk_length, 32));
        chunks.push_back(this_chunk);
        std::cout << this_chunk << "\n";
    }

    // for (auto letter_pos = 0; letter_pos < large_chunk_length; letter_pos++)
    //     {
    //         this_part_of_message = this_part_of_message + message_bin[letter_pos];
    //         if ((letter_pos+1)%small_chunk_length == 0 && letter_pos+1 > 1)  {
    //             small_chunks_bin.push_back(this_part_of_message);
    //             this_part_of_message = "";
    //         }
    //     }
    // small_chunks_bin = extend_chunks(small_chunks_bin);
}

// vector<string> SHA1::extend_chunks(vector<string> &chunks_bin)
// {
//     for (auto chunk_number = 16; chunk_number < 80; chunk_number++)
//         {
//             const string wordA = chunks_bin[chunk_number-3];
//             const string wordB = chunks_bin[chunk_number-8];
//             const string wordC = chunks_bin[chunk_number-14];
//             const string wordD = chunks_bin[chunk_number-16];

//             const string xorA = BitwiseXor(wordA, wordB); 
//             const string xorB = BitwiseXor(xorA, wordC);
//             const string xorC = BitwiseXor(xorB, wordD);

//             string newchunk;
//             newchunk = BitwiseLRotate(xorC,1);
//             chunks_bin.push_back(newchunk);
//         }
//     return chunks_bin;
// }

std::uint32_t sha1(const std::string data)  
{
    SHA1 hash;
    hash.transform(data);
    //return hash.final();
}