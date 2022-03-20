#include <string>
#include <vector>
#include <cstdint>

class SAGH
{
private:
    std::vector<std::string> chunks_bin;
    std::vector<std::string> digest;

public:
    SAGH();
    void update(const std::string &message);
    std::string final();

    std::string pad(std::string &message_bin);
    std::string pad_length_bin(std::string &length_bin);
    std::vector<std::string> cut_bin(std::string &length_bin);
    std::vector<std::string> extend_chunks(std::vector<std::string> &chunks_bin);
};

std::string left_rotate(std::string a, int n);

std::string bitwise_and(std::string s1, std::string s2);
std::string bitwise_or(std::string s1, std::string s2);
std::string bitwise_not(std::string s1);
std::string bitwise_xor(std::string s1, std::string s2);

std::string addBinary(std::string A, std::string B);

std::string sagh(const std::string &message);