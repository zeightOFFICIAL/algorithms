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
      uint32 bit32wiseRotate(uint32 first, u_long sizeToRotate);
      vector binToHex(string bin);
  
  public:
      SHA1();
      ~SHA1();
      void update(const string data);
      string final();
  };
  
  string sha1(const string data);
}