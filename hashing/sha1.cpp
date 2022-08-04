#include <bitset>
#include <sstream>
#include <vector>

#include "sha1.h"

SHA1::SHA1()
{
    chunks.clear();
    digest.clear();
    digest.push_back(0x67452301);
    digest.push_back(0xEFCDAB89);
    digest.push_back(0x98BADCFE);
    digest.push_back(0x10325476);
    digest.push_back(0xC3D2E1F0);
}
SHA1::~SHA1() {}

void SHA1::update(const std::string data)
{
    int message_length = data.length();
    std::string message_bin = "";
    std::string message_length_bin = std::bitset<8>(message_length * 8).to_string();
    for (size_t letter = 0; letter < message_length; letter++)
    {
        std::bitset<8> letter_bin = std::bitset<8>(data[letter]);
        message_bin = message_bin + letter_bin.to_string();
    }
    message_bin = message_bin + "1";
    message_bin = message_padding(message_bin);
    message_length_bin = length_bin_padding(message_length_bin);
    message_bin = message_bin + message_length_bin;
    split_to_chunks(message_bin);
    extend_chunks();
}

std::string SHA1::final()
{
    uint32_t a = digest[0];
    uint32_t b = digest[1];
    uint32_t c = digest[2];
    uint32_t d = digest[3];
    uint32_t e = digest[4];
    for (short this_rotation = 0; this_rotation < 80; this_rotation++)
    {
        uint32_t f, k;
        if (this_rotation < 20)
        {
            const uint32_t b_and_c = (b & c);
            const uint32_t not_b = (~(b)&d);
            f = (b_and_c | not_b);
            k = 0x5A827999;
        }
        else if (this_rotation < 40)
        {
            const uint32_t b_xor_c = (b ^ c);
            f = (b_xor_c ^ d);
            k = 0x6ED9EBA1;
        }
        else if (this_rotation < 60)
        {
            const uint32_t b_and_c = (b & c);
            const uint32_t b_and_d = (b & d);
            const uint32_t c_and_d = (c & d);
            const uint32_t bandc_or_bandd = (b_and_c | b_and_d);
            f = (bandc_or_bandd | c_and_d);
            k = 0x8F1BBCDC;
        }
        else if (this_rotation < 80)
        {
            const uint32_t b_xor_c = (b ^ c);
            f = (b_xor_c ^ d);
            k = 0xCA62C1D6;
        }
        const uint32_t chunk = chunks[this_rotation];
        const uint32_t temp_a = bit32wise_rotate(a, 5);
        const uint32_t temp = temp_a + f + e + k + chunk;

        e = d;
        d = c;
        c = bit32wise_rotate(b, 30);
        b = a;
        a = temp;
    }
    digest[0] = digest[0] + a;
    digest[1] = digest[1] + b;
    digest[2] = digest[2] + c;
    digest[3] = digest[3] + d;
    digest[4] = digest[4] + e;

    std::string hash = "";
    for (int this_string = 0; this_string < 5; this_string++)
    {
        std::stringstream binary_chunk;
        std::bitset<32> set(digest[this_string]);
        binary_chunk << std::hex << set.to_ulong();
        hash = hash + binary_chunk.str();
    }
    return hash;
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

void SHA1::split_to_chunks(const std::string message_bin)
{
    int small_chunk_length = 32;
    std::bitset<32> this_chunk;
    for (size_t chunk_index = 0; chunk_index < 16; chunk_index++)
    {
        this_chunk = std::bitset<32>(message_bin.substr(chunk_index * small_chunk_length, 32));
        chunks.push_back(this_chunk.to_ullong());
    }
}

void SHA1::extend_chunks()
{
    for (size_t chunk_number = 16; chunk_number <= 80; chunk_number++)
    {
        const uint32_t word_a = chunks[chunk_number - 3];
        const uint32_t word_b = chunks[chunk_number - 8];
        const uint32_t word_c = chunks[chunk_number - 14];
        const uint32_t word_d = chunks[chunk_number - 16];

        const uint32_t xor_a = (word_a ^ word_b);
        const uint32_t xor_b = (xor_a ^ word_c);
        const uint32_t xor_c = (xor_b ^ word_d);

        uint32_t new_chunk = bit32wise_rotate(xor_c, 1);
        chunks.push_back(new_chunk);
    }
}

uint32_t SHA1::bit32wise_rotate(uint32_t first, unsigned size_of_rotate)
{
    return (first << size_of_rotate) | (first >> (32 - size_of_rotate));
}

std::string SHA1::convert_bin_hex(std::string bin)
{
    std::bitset<32> set(bin);
    std::stringstream res;
    res << std::hex << set.to_ulong();
    return res.str();
}

std::string sha1(const std::string data)
{
    SHA1 hash;
    hash.update(data);
    return hash.final();
}