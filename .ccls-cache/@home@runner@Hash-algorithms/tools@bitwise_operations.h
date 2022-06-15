#include <string>
#include <bitset>

//bitwise operations for strings (sha1)
std::string BitwiseLRotate(std::string s1, int size_of_rotate);
std::string BitwiseAnd(std::string s1, std::string s2);
std::string BitwiseOr(std::string s1, std::string s2);
std::string BitwiseNot(std::string s1);
std::string BitwiseXor(std::string s1, std::string s2);
std::string BitwiseAdd(std::string s1, std::string s2);
bool BoolFullAdd(bool b1, bool b2, bool& carry);
std::bitset<32> BitsetAdd(std::bitset<32>& x, std::bitset<32>& y);

//convertation functions
std::uint32_t ConvertStrUint(std::string str);
std::string ConvertUintStr(std::uint32_t uint);
std::string ConvertBinHex(std::string bin);

//bitwise operations for uint32_t (sha256)
std::uint32_t Sigma0(std::uint32_t x);
std::uint32_t Sigma1(std::uint32_t x);
std::uint32_t RotateRight(std::uint32_t x, std::uint32_t n);
std::uint32_t RotateLeft(std::uint32_t x, std::uint32_t n);
std::uint32_t Choose(std::uint32_t e, std::uint32_t f, std::uint32_t g);
std::uint32_t Majority(std::uint32_t a, std::uint32_t b, std::uint32_t c);