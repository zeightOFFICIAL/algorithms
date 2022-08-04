#include <string>
#include <bitset>
#include <vector>
#include <sstream>

#include <iostream>

#include "sha256.h"

SHA256::SHA256()
{
    chunks.clear();
    digest.clear();
    digest.push_back(0x6A09E667);
    digest.push_back(0xBB67AE85);
    digest.push_back(0x3C6EF372);
    digest.push_back(0xA54FF53A);
    digest.push_back(0x510E527F);
    digest.push_back(0x9B05688C);
    digest.push_back(0x1F83D9AB);
    digest.push_back(0x5BE0CD19);
}
SHA256::~SHA256() {}

void SHA256::update(const std::string data)
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

std::string SHA256::final()
{
    uint32_t a = (digest[0]);
    uint32_t b = (digest[1]);
    uint32_t c = (digest[2]);
    uint32_t d = (digest[3]);
    uint32_t e = (digest[4]);
    uint32_t f = (digest[5]);
    uint32_t g = (digest[6]);
    uint32_t h = (digest[7]);
    for (short this_rotation = 0; this_rotation < 64; this_rotation++)
    {
        uint32_t majority = Majority(a, b, c);
        uint32_t xor_a = RotateRight(a, 2) ^ RotateRight(a, 13) ^ RotateRight(a, 22);
        uint32_t choose = Choose(e, f, g);
        uint32_t xor_e = RotateRight(e, 6) ^ RotateRight(e, 11) ^ RotateRight(e, 25);
        uint32_t sum = chunks[this_rotation] + SHA256::k[this_rotation] + h + choose + xor_e;
        uint32_t new_a = xor_a + majority + sum;
        uint32_t new_e = d + sum;

        h = g;
        g = f;
        f = e;
        e = new_e;
        d = c;
        c = b;
        b = a;
        a = new_a;
    }
    digest[0] = digest[0] + a;
    digest[1] = digest[1] + b;
    digest[2] = digest[2] + c;
    digest[3] = digest[3] + d;
    digest[4] = digest[4] + e;
    digest[5] = digest[5] + f;
    digest[6] = digest[6] + g;
    digest[7] = digest[7] + h;

    std::string hash = "";
    for (int this_string = 0; this_string < 8; this_string++)
    {
        std::stringstream binary_chunk;
        std::bitset<32> set(digest[this_string]);
        binary_chunk << std::hex << set.to_ulong();
        hash = hash + binary_chunk.str();
    }
    return hash;
}

std::string SHA256::message_padding(std::string message_bin)
{
    while (message_bin.length() % 512 != 448)
        message_bin = message_bin + '0';
    return message_bin;
}

std::string SHA256::length_bin_padding(std::string length_bin)
{
    while (length_bin.length() != 64)
        length_bin = '0' + length_bin;
    return length_bin;
}

void SHA256::split_to_chunks(const std::string message_bin)
{
    int small_chunk_length = 32;
    std::bitset<32> this_chunk;
    for (size_t chunk_index = 0; chunk_index < 16; chunk_index++)
    {
        this_chunk = std::bitset<32>(message_bin.substr(chunk_index * small_chunk_length, 32));
        chunks.push_back(this_chunk.to_ullong());
    }
}

void SHA256::extend_chunks()
{
    for (int chunk_number = 16; chunk_number < 64; chunk_number++)
    {
        uint32_t w_15 = chunks[chunk_number - 15];
        uint32_t w_2 = chunks[chunk_number - 2];
        uint32_t w_7 = chunks[chunk_number - 7];
        uint32_t w_16 = chunks[chunk_number - 16];

        uint32_t current_w = Sigma1(w_2) + w_7 + Sigma0(w_15) + w_16;
        chunks.push_back(current_w);
    }
}

uint32_t SHA256::Sigma0(uint32_t x)
{
    return RotateRight(x, 7) ^ RotateRight(x, 18) ^ (x >> 3);
}

uint32_t SHA256::Sigma1(uint32_t x)
{
    return RotateRight(x, 17) ^ RotateRight(x, 19) ^ (x >> 10);
}

uint32_t SHA256::RotateRight(uint32_t x, uint32_t n)
{
    return (x >> n) | (x << (32 - n));
}

uint32_t SHA256::RotateLeft(uint32_t x, uint32_t n)
{
    return (x << n) | (x >> (32 - n));
}

uint32_t SHA256::Choose(uint32_t e, uint32_t f, uint32_t g)
{
    return (e & f) ^ (~e & g);
}

uint32_t SHA256::Majority(uint32_t a, uint32_t b, uint32_t c)
{
    return (a & (b | c)) | (b & c);
}

std::string sha256(const std::string data)
{
    SHA256 hash;
    hash.update(data);
    return hash.final();
}