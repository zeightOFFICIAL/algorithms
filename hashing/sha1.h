//sha1.h 1005
#pragma once

#include <vector>
#include <bitset>

class SHA1
{
private:
    std::vector<std::bitset<32>> chunks;
    std::vector<std::bitset<32>> digest;

    std::string message_padding(std::string message_bin);
    std::string length_bin_padding(std::string length_bin);
    void split_to_chunks(std::string message_bin);
    void extend_chunks();
    std::bitset<32> bitsetwise_add(std::bitset<32> first, std::bitset<32> second);
    bool bool_full_add(bool b1, bool b2, bool& carry_over);
    std::bitset<32> bitsetwise_rotate(std::bitset<32> first, unsigned size_of_rotate);
    std::string convert_bin_hex(std::string bin);
public:
    SHA1();
    ~SHA1();
    void transform(const std::string data);
    std::string process();
};

std::string sha1(const std::string data);