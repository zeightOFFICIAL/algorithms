// sha1.h 1008
#pragma once

#include <vector>
#include <bitset>

class SHA1
{
private:
    std::vector<uint32_t> chunks;
    std::vector<uint32_t> digest;

    std::string message_padding(std::string message_bin);
    std::string length_bin_padding(std::string length_bin);
    void split_to_chunks(const std::string message_bin);
    void extend_chunks();
    uint32_t bit32wise_rotate(uint32_t first, unsigned size_of_rotate);
    std::string convert_bin_hex(std::string bin);

public:
    SHA1();
    ~SHA1();
    void update(const std::string data);
    std::string final();
};

std::string sha1(const std::string data);