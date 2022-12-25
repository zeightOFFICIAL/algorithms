#include "sha256.h"

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
    u_long dateLength = data.length();
    string binaryData = "";
    string binaryDateLen = bitset8(dateLength * 8).to_string();
    for (u_long letter = 0; letter < dateLength; letter++) {
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
  
  string sha256(const string data) {
    SHA256 hash;
    hash.update(data);
    return hash.final();
  }
} // namespace hashing