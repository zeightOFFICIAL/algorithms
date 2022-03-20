#include "sha256.h"

sha256::sha256(): block_length(0), bit_length(0) {
	h_table[0] = 0x6a09e667;
	h_table[1] = 0xbb67ae85;
	h_table[2] = 0x3c6ef372;
	h_table[3] = 0xa54ff53a;
	h_table[4] = 0x510e527f;
	h_table[5] = 0x9b05688c;
	h_table[6] = 0x1f83d9ab;
	h_table[7] = 0x5be0cd19;
}