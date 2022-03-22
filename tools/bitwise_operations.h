#include <string>
#include <bitset>

/**
    these are different bitwise operations specially transformed 
    for the needs of sha1, in particular for operations with 
    strings.
*/

std::string bitwise_left_rotate(std::string s1, int size_of_rotate);
std::string bitwise_right_rotate(std::string s1, int size_of_rotate);
std::string bitwise_right_shift(std::string s1, int size_of_shift);
std::string bitwise_and(std::string s1, std::string s2);
std::string bitwise__or(std::string s1, std::string s2);
std::string bitwise_not(std::string s1);
std::string bitwise_xor(std::string s1, std::string s2);
std::string bitwise_add(std::string s1, std::string s2);

bool bool_full_adder(bool b1, bool b2, bool& carry);
std::bitset<32> bitset_add(std::bitset<32>& x, std::bitset<32>& y);

std::bitset<32> bit_wise_sigma0(std::string ch1);
std::bitset<32> bit_wise_sigma1(std::string ch1);

std::string convert_bin_to_hex(std::string bin);