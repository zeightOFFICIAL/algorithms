/*
Zeight Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// sha1.h

#include "_Utils.h"

namespace hashing {
  class SHA1
  {
  private:
      vector chunks;
      vector digest;
  
      string messagePadding(string binaryMessage);
      string binaryLenPadding(string binaryLength);
      void splitToChunks(const string binaryMessage);
      void extendChunks();
      uint32 bit32wiseRotate(uint32 first, ulong sizeToRotate);
      string binToHex(string bin);
  
  public:
      SHA1();
      ~SHA1();
      void update(const string data);
      string final();
  };

  /**
  (string A) -> (string B)
  Creates hash B of string A, using
  SHA1 hashing function. 
  Return string B - hash.
  */
  static string sha1(const string data);
} // namespace hashing

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
    ulong dataLength = data.length();
    string binaryData = "";
    string binaryDataLen = bitset8(dataLength * 8).to_string();
    for (ulong letter = 0; letter < dataLength; letter++) {
      bitset8 binaryLetter = std::bitset<8>(data[letter]);
      binaryData = binaryData + binaryLetter.to_string();
    }
    binaryData = binaryData + "1";
    binaryData = messagePadding(binaryData);
    binaryDataLen = binaryLenPadding(binaryDataLen);
    binaryData = binaryData + binaryDataLen;
    splitToChunks(binaryData);
    extendChunks();
  }
  
  std::string SHA1::final() {
    uint32 a = digest[0];
    uint32 b = digest[1];
    uint32 c = digest[2];
    uint32 d = digest[3];
    uint32 e = digest[4];
    
    for (char thisRotation = 0; thisRotation < 80; thisRotation++) {
      uint32 f, k;
      if (thisRotation < 20) {
        const uint32 BandC = (b & c);
        const uint32 notB = (~(b)&d);
        f = (BandC | notB);
        k = 0x5A827999;
      } else if (thisRotation < 40) {
        const uint32 BxorC = (b ^ c);
        f = (BxorC ^ d);
        k = 0x6ED9EBA1;
      } else if (thisRotation < 60) {
        const uint32 BandC = (b & c);
        const uint32 BandD = (b & d);
        const uint32 CandD = (c & d);
        const uint32 BandCorBandD = (BandC | BandD);
        f = (BandCorBandD | CandD);
        k = 0x8F1BBCDC;
      } else if (thisRotation < 80) {
        const uint32 BxorC = (b ^ c);
        f = (BxorC ^ d);
        k = 0xCA62C1D6;
      }
      const uint32 chunk = chunks[thisRotation];
      const uint32 tempA = bit32wiseRotate(a, 5);
      const uint32 temp = tempA + f + e + k + chunk;  
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
  
    string hash = "";
    for (char hexIndex = 0; hexIndex < 5; hexIndex++) {
      strstream binaryChunk;
      bitset32 set(digest[hexIndex]);
      binaryChunk << std::hex << set.to_ulong();
      hash = hash + binaryChunk.str();
    }
    return hash;
  }
  
  string SHA1::messagePadding(string binaryData) {
    while (binaryData.length() % 512 != 448)
      binaryData = binaryData + '0';
    return binaryData;
  }
  
  string SHA1::binaryLenPadding(string binaryLen) {
    while (binaryLen.length() != 64)
      binaryLen = '0' + binaryLen;
    return binaryLen;
  }
  
  void SHA1::splitToChunks(const string binaryData) {
    int chunkSize = 32;
    bitset32 chunk;
    
    for (ulong index = 0; index < 16; index++) {
      chunk = bitset32(binaryData.substr(index * chunkSize, 32));
      chunks.push_back(chunk.to_ullong());
    }
  }
  
  void SHA1::extendChunks() {
    for (ulong indexChunk = 16; indexChunk <= 80; indexChunk++) {
      const uint32 wordA = chunks[indexChunk - 3];
      const uint32 wordB = chunks[indexChunk - 8];
      const uint32 wordC = chunks[indexChunk - 14];
      const uint32 wordD = chunks[indexChunk - 16];
  
      const uint32 xorA = (wordA ^ wordB);
      const uint32 xorB = (xorA ^ wordC);
      const uint32 xorC = (xorB ^ wordD);
  
      uint32 newChunk = bit32wiseRotate(xorC, 1);
      chunks.push_back(newChunk);
    }
  }
  
  uint32 SHA1::bit32wiseRotate(uint32 first, ulong sizeToRotate) {
    return (first << sizeToRotate) | (first >> (32 - sizeToRotate));
  }
  
  string SHA1::binToHex(string bin) {
    bitset32 set(bin);
    strstream res;
    res << std::hex << set.to_ulong();
    return res.str();
  }

  static std::string sha1(const std::string data) {
    SHA1 hash;
    hash.update(data);
    return hash.final();
  }
} // namespace hashing