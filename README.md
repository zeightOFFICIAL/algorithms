# Hashing algorithms

Comparison of hashing algorithms

* Version 1.0

A hash function is any function that can be used to map data of arbitrary size to fixed-size values. The values returned by a hash function are called hash values, hash codes, digests, or simply hashes. The values are usually used to index a fixed-size table called a hash table. Use of a hash function to index a hash table is called hashing or scatter storage addressing.

Hash functions and their associated hash tables are used in data storage and retrieval applications to access data in a small and nearly constant time per retrieval. They require an amount of storage space only fractionally greater than the total space required for the data or records themselves. Hashing is a computationally and storage space-efficient form of data access that avoids the non-constant access time of ordered and unordered lists and structured trees, and the often exponential storage requirements of direct access of state spaces of large or variable-length keys.

Use of hash functions relies on statistical properties of key and function interaction: worst-case behaviour is intolerably bad with a vanishingly small probability, and average-case behaviour can be nearly optimal (minimal collision).

Hash functions are related to (and often confused with) checksums, check digits, fingerprints, lossy compression, randomization functions, error-correcting codes, and ciphers. Although the concepts overlap to some extent, each one has its own uses and requirements and is designed and optimized differently. The hash function differs from these concepts mainly in terms of data integrity.

Currently available algorithms:

* <b><em>Adler-32</b></em> is a checksum algorithm which was written by Mark Adler in 1995, and is a modification of the Fletcher checksum. Compared to a cyclic redundancy check of the same length, it trades reliability for speed (preferring the latter). Adler-32 is more reliable than Fletcher-16, and slightly less reliable than Fletcher-32. <b>(implemented: adler32)</b>
* <b><em>Fowler–Noll–Vo</b></em> (or FNV) is a non-cryptographic hash function created by Glenn Fowler, Landon Curt Noll, and Kiem-Phong Vo. <b>(implemented: fnv132)</b>
* <b><em>SHA-1</b></em> (Secure Hash Algorithm 1) is a cryptographically broken but still widely used hash function which takes an input and produces a 160-bit (20-byte) hash value known as a message digest – typically rendered as a hexadecimal number, 40 digits long. It was designed by the United States National Security Agency, and is a U.S. Federal Information Processing Standard. <b>(implemented: sha1)</b>
* <b><em>SHA-2</b></em> (Secure Hash Algorithm 2) is a set of cryptographic hash functions designed by the United States National Security Agency (NSA) and first published in 2001. They are built using the Merkle–Damgård construction, from a one-way compression function itself built using the Davies–Meyer structure from a specialized block cipher. <b>(implemented: sha256)</b>
