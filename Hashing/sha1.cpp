#include "sha1.h"

namespace hashing {
  SHA1::SHA1() {
    chunks.clear();
    digest.clear();
    digest.push_back(0x67452301);
    digest.push_back(0xEFCDAB89);
    digest.push_back(0x98BADCFE);
    digest.push_back(0x10325476);
    digest.push_back(0xC3D2E1F0);
  }
  SHA1::~SHA1() {}
  
  void SHA1::update(const string data) {
    int message_length = data.length();
    string message_bin = "";
    string message_length_bin = bitset8(message_length * 8).to_string();
    for (size_t letter = 0; letter < message_length; letter++) {
      bitset8 letter_bin = std::bitset<8>(data[letter]);
      message_bin = message_bin + letter_bin.to_string();
    }
    message_bin = message_bin + "1";
    message_bin = messagePadding(message_bin);
    message_length_bin = binaryLenPadding(message_length_bin);
    message_bin = message_bin + message_length_bin;
    splitToChunks(message_bin);
    extendChunks();
  }
  
  std::string SHA1::final() {
    uint32 a = digest[0];
    uint32 b = digest[1];
    uint32 c = digest[2];
    uint32 d = digest[3];
    uint32 e = digest[4];
    for (short this_rotation = 0; this_rotation < 80; this_rotation++) {
      uint32 f, k;
      if (this_rotation < 20) {
        const uint32 b_and_c = (b & c);
        const uint32 not_b = (~(b)&d);
        f = (b_and_c | not_b);
        k = 0x5A827999;
      } else if (this_rotation < 40) {
        const uint32 b_xor_c = (b ^ c);
        f = (b_xor_c ^ d);
        k = 0x6ED9EBA1;
      } else if (this_rotation < 60) {
        const uint32 b_and_c = (b & c);
        const uint32 b_and_d = (b & d);
        const uint32 c_and_d = (c & d);
        const uint32 bandc_or_bandd = (b_and_c | b_and_d);
        f = (bandc_or_bandd | c_and_d);
        k = 0x8F1BBCDC;
      } else if (this_rotation < 80) {
        const uint32 b_xor_c = (b ^ c);
        f = (b_xor_c ^ d);
        k = 0xCA62C1D6;
      }
      const uint32 chunk = chunks[this_rotation];
      const uint32 temp_a = bit32wiseRotate(a, 5);
      const uint32 temp = temp_a + f + e + k + chunk;
  
      e = d;
      d = c;
      c = bit32wiseRotate(b, 30);
      b = a;
      a = temp;
    }
    digest[0] = digest[0] + a;
    digest[1] = digest[1] + b;
    digest[2] = digest[2] + c;
    digest[3] = digest[3] + d;
    digest[4] = digest[4] + e;
  
    std::string hash = "";
    for (int this_string = 0; this_string < 5; this_string++) {
      std::stringstream binary_chunk;
      std::bitset<32> set(digest[this_string]);
      binary_chunk << std::hex << set.to_ulong();
      hash = hash + binary_chunk.str();
    }
    return hash;
  }
  
  std::string SHA1::messagePadding(std::string message_bin) {
    while (message_bin.length() % 512 != 448)
      message_bin = message_bin + '0';
    return message_bin;
  }
  
  std::string SHA1::binaryLenPadding(std::string length_bin) {
    while (length_bin.length() != 64)
      length_bin = '0' + length_bin;
    return length_bin;
  }
  
  void SHA1::splitToChunks(const std::string message_bin) {
    int small_chunk_length = 32;
    std::bitset<32> this_chunk;
    for (size_t chunk_index = 0; chunk_index < 16; chunk_index++) {
      this_chunk = std::bitset<32>(
          message_bin.substr(chunk_index * small_chunk_length, 32));
      chunks.push_back(this_chunk.to_ullong());
    }
  }
  
  void SHA1::extendChunks() {
    for (size_t chunk_number = 16; chunk_number <= 80; chunk_number++) {
      const uint32_t word_a = chunks[chunk_number - 3];
      const uint32_t word_b = chunks[chunk_number - 8];
      const uint32_t word_c = chunks[chunk_number - 14];
      const uint32_t word_d = chunks[chunk_number - 16];
  
      const uint32_t xor_a = (word_a ^ word_b);
      const uint32_t xor_b = (xor_a ^ word_c);
      const uint32_t xor_c = (xor_b ^ word_d);
  
      uint32_t new_chunk = bit32wiseRotate(xor_c, 1);
      chunks.push_back(new_chunk);
    }
  }
  
  uint32 SHA1::bit32wiseRotate(uint32_t first, unsigned size_of_rotate) {
    return (first << size_of_rotate) | (first >> (32 - size_of_rotate));
  }
  
  std::string SHA1::binToHex(std::string bin) {
    std::bitset<32> set(bin);
    std::stringstream res;
    res << std::hex << set.to_ulong();
    return res.str();
  }
  
  std::string sha1(const std::string data) {
    SHA1 hash;
    hash.update(data);
    return hash.final();
  }
} // namespace hashing