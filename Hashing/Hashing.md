# SHA1
SHA-1 (Secure Hash Algorithm 1) is a cryptographic hashing function that generates a fixed-size, 160-bit hash value from any input data. It is one of the most widely used hashing algorithms and is designed to be secure against brute-force attacks and other cryptographic attacks. SHA-1 is a one-way function, meaning that it is easy to compute the hash value of any given input, but it is computationally infeasible to generate the original input data from the hash value alone. The SHA-1 algorithm works by breaking the input data into fixed-size blocks and processing them one at a time through a series of mathematical operations. The resulting hash value is a unique representation of the original input data and is commonly used for digital signatures, message authentication, and other security applications. However, SHA-1 is now considered insecure for certain use cases due to its vulnerability to collision attacks, and newer hashing algorithms such as SHA-2 and SHA-3 are recommended for use instead.

# SHA2 (SHA256)
SHA2 (Secure Hash Algorithm 2) is a family of cryptographic hash functions designed by the National Security Agency (NSA) and published by the National Institute of Standards and Technology (NIST) as a U.S. Federal Information Processing Standard (FIPS). SHA256 is a specific implementation of SHA2 that generates a 256-bit hash value. SHA256 takes an input message and processes it through a series of cryptographic operations to produce a fixed-length output. It is widely used in various security protocols and applications to ensure data integrity and authenticity. Despite its widespread use, SHA256 is vulnerable to certain attacks, and newer hash functions such as SHA3 are recommended for use in new applications.

# FNV (FNV32, FNV64)
FNV (Fowler–Noll–Vo) Hash Function is a non-cryptographic hash function that was created by Glenn Fowler, Landon Curt Noll, and Kiem-Phong Vo. It is a simple and fast hash function that is widely used in various applications, including computer networking and operating systems.

The FNV Hash Function uses a multiplication and XOR operation to produce a hash value. It has a tunable parameter, which allows users to choose the size of the hash output. FNV hash function is known for its good distribution and low collision rate, which makes it suitable for hash table implementations.

# Adler32 (Adler32)
Adler-32 is a checksum algorithm that computes a 32-bit checksum value from a block of data of any length. The algorithm is named after its creator, Mark Adler, and was published in 1995.

Adler-32 is a fast checksum algorithm that is widely used in network protocols and file formats, such as zlib and gzip. It is also used in some versions of the BitTorrent protocol to verify the integrity of downloaded files. However, it is not considered to be a secure cryptographic hash function, as it can be easily compromised by an attacker who has access to the data being checksummed.

# Fletcher (Fletcher 8bit, Fletcher 16bit, Fletcher 32bit)
Fletcher's checksum algorithm is a type of cyclic redundancy check (CRC) algorithm that was developed by John G. Fletcher in the 1980s. It is used to detect errors in data transmission by adding a checksum value to the data that can be used to verify the integrity of the data.

Fletcher's checksum algorithm is simple and efficient, and can detect a wide range of errors in data transmission, including single-bit errors, transposition errors, and many common types of burst errors. However, it is not as robust as some other CRC algorithms, and may not be suitable for applications that require very high levels of error detection.