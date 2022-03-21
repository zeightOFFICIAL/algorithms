#include <string>
#include <vector>
#include <cstdint>
#include <bitset>

class SAGH
{
private:
    std::vector<std::string> chunks_bin;
    std::vector<std::string> digest;

public:
    SAGH();
    void update(const std::string &message);
    std::string final();

    std::string pad_message_bin(std::string &message_bin);
    std::string pad_length_bin(std::string &length_bin);
    std::vector<std::string> split_to_chunks(std::string &length_bin);
    std::vector<std::string> extend_chunks(std::vector<std::string> &chunks_bin);
};

std::string bitwise_left_rotate(std::string s1, int size_of_shift);
std::string bitwise_and(std::string s1, std::string s2);
std::string bitwise__or(std::string s1, std::string s2);
std::string bitwise_not(std::string s1);
std::string bitwise_xor(std::string s1, std::string s2);
std::string bitwise_add(std::string s1, std::string s2);

std::string convert_bin_to_hex(std::string bin);


std::string sagh(const std::string &message);

bool fullAdder(bool b1, bool b2, bool& carry);
std::bitset<32> bitsetAdd(std::bitset<32>& x, std::bitset<32>& y);