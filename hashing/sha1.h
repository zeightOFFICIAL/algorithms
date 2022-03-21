#include <string>
#include <vector>

class SHA1
{
private:
    std::vector<std::string> chunks_bin;
    std::vector<std::string> digest;

public:
    SHA1();
    void update(const std::string &message);
    std::string final();

    std::string pad_message_bin(std::string &message_bin);
    std::string pad_length_bin(std::string &length_bin);
    std::vector<std::string> split_to_chunks(std::string &message_bin);
    std::vector<std::string> extend_chunks(std::vector<std::string> &chunks_bin);
};

std::string convert_bin_to_hex(std::string bin);
std::string sha1(const std::string &message);