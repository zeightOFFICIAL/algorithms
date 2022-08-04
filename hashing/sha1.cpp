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
    std::string message_length_bin = std::bitset<8>(message_length*8).to_string();
    for (size_t letter = 0; letter < message_length; letter++) {
        std::bitset<8> letter_bin = std::bitset<8>(message[letter]);
        message_bin = message_bin + letter_bin.to_string();
    }
    message_bin = message_bin + "1";
    message_bin = message_padding(message_bin);
    message_length_bin = length_bin_padding(message_length_bin);
    message_bin = message_bin + message_length_bin;
    split_to_chunks(message_bin);
    extend_chunks();
}

std::string SHA1::process()
{
    std::bitset<32> a = digest[0];
    std::bitset<32> b = digest[1];
    std::bitset<32> c = digest[2];
    std::bitset<32> d = digest[3];
    std::bitset<32> e = digest[4]; 
            for (int this_rotation = 0; this_rotation < 80; this_rotation++)  {  
                std::bitset<32> f,k;
                    if (this_rotation < 20)  {
                        const std::bitset<32> b_and_c = (b & c);
                        const std::bitset<32> not_b = (~(b) & d);
                        f = (b_and_c | not_b);
                        k = 0x5A827999;
                    }
                    else if (this_rotation < 40) {
                        const std::bitset<32> b_xor_c = (b ^ c);
                        f = (b_xor_c ^ d);
                        k = 0x6ED9EBA1;
                    }
                    else if (this_rotation < 60) {
                        const std::bitset<32> b_and_c = (b & c);
                        const std::bitset<32> b_and_d = (b & d);
                        const std::bitset<32> c_and_d = (c & d);
                        const std::bitset<32> bandc_or_bandd = (b_and_c | b_and_d);
                        f = (bandc_or_bandd | c_and_d);
                        k = 0x8F1BBCDC;
                    }
                    else  {
                        const std::bitset<32> b_xor_c = (b ^ c);
                        f = (b_xor_c ^ d);
                        k = 0xCA62C1D6;
                    }
                    const std::bitset<32> chunk = chunks[this_rotation];
                    const std::bitset<32> temp_a = bitsetwise_rotate(a, 5);
                    // std::bitset<32> temp = bitsetwise_add(temp_a, f);
                    // temp = bitsetwise_add(temp, f);
                    // temp = bitsetwise_add(temp, e);
                    // temp = bitsetwise_add(temp, k);
                    // temp = bitsetwise_add(temp, chunk);
                    uint32_t temp = temp_a.to_ullong() + f.to_ullong() + e.to_ullong() + k.to_ullong() + chunk.to_ullong();

                    e = d;
                    d = c;
                    c = bitsetwise_rotate(b, 30);
                    b = a;
                    a = std::bitset<32>(temp);
                }
            digest[0] = digest[0].to_ullong() + a.to_ullong();
            digest[1] = digest[1].to_ullong() + b.to_ullong();
            digest[2] = digest[2].to_ullong() + c.to_ullong();
            digest[3] = digest[3].to_ullong() + d.to_ullong();
            digest[4] = digest[4].to_ullong() + e.to_ullong();

    std::string unite_digest = "";
    for (int this_string = 0; this_string < 5; this_string++) {
        unite_digest = unite_digest + convert_bin_hex(digest[this_string].to_string());
    }
    return unite_digest;
}

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
    }
}

void SHA1::extend_chunks()
{
    for (size_t chunk_number = 16; chunk_number <= 80; chunk_number++)
        {
            const std::bitset<32> word_a = chunks[chunk_number-3];
            const std::bitset<32> word_b = chunks[chunk_number-8];
            const std::bitset<32> word_c = chunks[chunk_number-14];
            const std::bitset<32> word_d = chunks[chunk_number-16];

            const std::bitset<32> xor_a = (word_a ^ word_b); 
            const std::bitset<32> xor_b = (xor_a ^ word_c);
            const std::bitset<32> xor_c = (xor_b ^ word_d);

            std::bitset<32> new_chunk = bitsetwise_rotate(xor_c, 1);
            chunks.push_back(new_chunk);
        }
}

std::bitset<32> SHA1::bitsetwise_add(std::bitset<32> first, std::bitset<32> second) 
{
    std::string result = "";
    //std::cout << first_int << " " << second_int << " " << result_str << "\n";

    return std::bitset<32>(result);
}

std::bitset<32> SHA1::bitsetwise_rotate(std::bitset<32> first, unsigned size_of_rotate)
{
    return (first << size_of_rotate) | (first >> (32 - size_of_rotate));
}

std::string SHA1::convert_bin_hex(std::string bin)  {
    std::bitset<32> set(bin);
    std::stringstream res;
    res << std::hex << set.to_ulong();
    return res.str();
}

std::string sha1(const std::string data)  
{
    SHA1 hash;
    hash.transform(data);
    return hash.process();
}