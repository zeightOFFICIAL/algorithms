//sha1.h 1004
#pragma once

#include <vector>
#include <bitset>

class SHA1
{
private:
    std::vector<std::bitset<32>> chunks;
    std::vector<uint32_t> digest;

    std::string message_padding(std::string message_bin);
    std::string length_bin_padding(std::string length_bin);
    void split_to_chunks(std::string message_bin);
    //std::vector<std::string> extend_chunks(std::vector<std::string> &chunks_bin);
public:
    SHA1();
    ~SHA1();
    void transform(const std::string data);
    std::string process();
};

std::uint32_t sha1(const std::string data);