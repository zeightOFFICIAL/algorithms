/*
Zeight Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// sha256.h

#include "_Utils.h"

namespace hashing {
  class SHA256 {
  private:
    vector digest;
    vector chunks;
    uint32 k[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
        0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
        0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
        0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
        0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
        0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};
  
    string messagePadding(string binaryMessage);
    string binaryLenPadding(string binaryLength);
    void splitToChunks(const string binaryMessage);
    void extendChunks();

    uint32 Sigma0(uint32 x);
    uint32 Sigma1(uint32 x);
    uint32 RotateRight(uint32 x, uint32 sizeToRotate);
    uint32 RotateLeft(uint32 x, uint32 sizeToRotate);
    uint32 Choose(uint32 e, uint32 f, uint32 g);
    uint32 Majority(uint32 a, uint32 b, uint32 c);
  
  public:
    SHA256();
    ~SHA256();
    void update(const string data);
    string final();
  };

  /**
  (string A) -> (string B)
  Creates hash B of string A, using
  SHA256 hashing function. 
  Return string B - hash.
  */
  static string sha256(const string data);
} // namespace hashing

namespace hashing {
  SHA256::SHA256() {
    chunks.clear();
    digest.clear();
    digest.push_back(0x6A09E667);
    digest.push_back(0xBB67AE85);
    digest.push_back(0x3C6EF372);
    digest.push_back(0xA54FF53A);
    digest.push_back(0x510E527F);
    digest.push_back(0x9B05688C);
    digest.push_back(0x1F83D9AB);
    digest.push_back(0x5BE0CD19);
  }
  SHA256::~SHA256() {}
  
  void SHA256::update(const string data) {
    ulong dateLength = data.length();
    string binaryData = "";
    string binaryDateLen = bitset8(dateLength * 8).to_string();
    for (ulong letter = 0; letter < dateLength; letter++) {
      bitset8 binaryLetter = bitset8(data[letter]);
      binaryData = binaryData + binaryLetter.to_string();
    }
    binaryData = binaryData + "1";
    binaryData = messagePadding(binaryData);
    binaryDateLen = binaryLenPadding(binaryDateLen);
    binaryData = binaryData + binaryDateLen;
    splitToChunks(binaryData);
    extendChunks();
  }
  
  string SHA256::final() {
    uint32 a = (digest[0]);
    uint32 b = (digest[1]);
    uint32 c = (digest[2]);
    uint32 d = (digest[3]);
    uint32 e = (digest[4]);
    uint32 f = (digest[5]);
    uint32 g = (digest[6]);
    uint32 h = (digest[7]);
    
    for (char thisRotation = 0; thisRotation < 64; thisRotation++) {
      uint32 majority = Majority(a, b, c);
      uint32 xorA = RotateRight(a, 2) ^ RotateRight(a, 13) ^ RotateRight(a, 22);
      uint32 choose = Choose(e, f, g);
      uint32 xorE = RotateRight(e, 6) ^ RotateRight(e, 11) ^ RotateRight(e, 25);
      uint32 sum = chunks[thisRotation] + SHA256::k[thisRotation] + h + choose + xorE;
      uint32 newA = xorA + majority + sum;
      uint32 newE = d + sum;
  
      h = g;
      g = f;
      f = e;
      e = newE;
      d = c;
      c = b;
      b = a;
      a = newA;
    }
    digest[0] = digest[0] + a;
    digest[1] = digest[1] + b;
    digest[2] = digest[2] + c;
    digest[3] = digest[3] + d;
    digest[4] = digest[4] + e;
    digest[5] = digest[5] + f;
    digest[6] = digest[6] + g;
    digest[7] = digest[7] + h;
  
    string hash = "";
    for (char hashIndex = 0; hashIndex < 8; hashIndex++) {
      strstream binaryChunk;
      bitset32 set(digest[hashIndex]);
      binaryChunk << std::hex << set.to_ulong();
      hash = hash + binaryChunk.str();
    }
    return hash;
  }
  
  string SHA256::messagePadding(string binaryData) {
    while (binaryData.length() % 512 != 448)
      binaryData = binaryData + '0';
    return binaryData;
  }
  
  string SHA256::binaryLenPadding(string binaryLength) {
    while (binaryLength.length() != 64)
      binaryLength = '0' + binaryLength;
    return binaryLength;
  }
  
  void SHA256::splitToChunks(const string binaryData) {
    int chunkSize = 32;
    bitset32 chunk;
    
    for (char index = 0; index < 16; index++) {
      chunk = bitset32(binaryData.substr(index * chunkSize, 32));
      chunks.push_back(chunk.to_ullong());
    }
  }
  
  void SHA256::extendChunks() {
    for (int indexChunk = 16; indexChunk < 64; indexChunk++) {
      uint32 w15 = chunks[indexChunk - 15];
      uint32 w2 = chunks[indexChunk - 2];
      uint32 w7 = chunks[indexChunk - 7];
      uint32 w16 = chunks[indexChunk - 16];
  
      uint32 currentW = Sigma1(w2) + w7 + Sigma0(w15) + w16;
      chunks.push_back(currentW);
    }
  }
  
  uint32 SHA256::Sigma0(uint32 x) {
    return RotateRight(x, 7) ^ RotateRight(x, 18) ^ (x >> 3);
  }
  
  uint32 SHA256::Sigma1(uint32 x) {
    return RotateRight(x, 17) ^ RotateRight(x, 19) ^ (x >> 10);
  }
  
  uint32 SHA256::RotateRight(uint32 x, uint32 sizeToRotate) {
    return (x >> sizeToRotate) | (x << (32 - sizeToRotate));
  }
  
  uint32 SHA256::RotateLeft(uint32 x, uint32 sizeToRotate) {
    return (x << sizeToRotate) | (x >> (32 - sizeToRotate));
  }
  
  uint32 SHA256::Choose(uint32 e, uint32_t f, uint32 g) {
    return (e & f) ^ (~e & g);
  }
  
  uint32 SHA256::Majority(uint32 a, uint32 b, uint32 c) {
    return (a & (b | c)) | (b & c);
  }
  
  static string sha256(const string data) {
    SHA256 hash;
    hash.update(data);
    return hash.final();
  }
} // namespace hashing