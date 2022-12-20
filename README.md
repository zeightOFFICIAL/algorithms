<<<<<<< HEAD
<<<<<<< HEAD
# Algorithms

The word Algorithm means: "a set of rules to be followed in calculations or other problem-solving operations" or "a procedure for solving a mathematical problem in a finite number of steps".
In mathematics and computer science, an algorithm is a finite sequence of rigorous instructions, typically used to solve a class of specific problems or to perform a computation. Algorithms are used as specifications for performing calculations and data processing. By making use of artificial intelligence, algorithms can perform automated deductions (referred to as automated reasoning) and use mathematical and logical tests to divert the code execution through various routes (referred to as automated decision-making). Using human characteristics as descriptors of machines in metaphorical ways was already practiced by Alan Turing with terms such as "memory", "search" and "stimulus".

---
## Sorting

In computer science, a sorting algorithm is an algorithm that puts elements of a list into an order. The most frequently used orders are numerical order and lexicographical order, and either ascending or descending. Efficient sorting is important for optimizing the efficiency of other algorithms (such as search and merge algorithms) that require input data to be in sorted lists. Sorting is also often useful for canonicalizing data and for producing human-readable output.
Currently available algorithms:
* <b><em>Bubble sort</em></b>
* <b><em>Comb sort</em></b>

* <b><em>Cocktail sort</em></b> is an advanced two-directional bubble sort. The man idea behind cocktail sort is about moving the min and max value to the sides. Firstly, we move the biggest to the right end of the array, then we go backwards and move the smallest to the left side. Gradually the array becomes sorted, as we move element by element to the proper side, as if we were shaking with array from left to right and so on. Comparison of neighbors (exchanging). Stable: yes. Best case: O(n). Worst case: O(n^2).
<p align="center">
  <img width="50%" src="https://user-images.githubusercontent.com/50341618/206593118-86c9b07d-f473-4443-84b4-1f0a95cc3cc8.gif">
</p>

* <b><em>Heap sort</em></b>
* <b><em>Insertion sort</em></b>
* <b><em>Gnome sort</em></b>
* <b><em>Stooge sort</em></b> 

## Substring search

In computer science, string-searching algorithms, sometimes called string-matching algorithms, are an important class of string algorithms that try to find a place where one or several strings (also called patterns) are found within a larger string or text. A basic example of string searching is when the pattern and the searched text are arrays of elements of an alphabet.
Currently available algorithms:
* <b><em>Boyer-Moore</em></b> 
* <b><em>Knuth–Morris–Pratt</em></b> 
* <b><em>Rabin-Karp</em></b> 
* <b><em>Naïve algorithm</em></b>
* <b><em>Bitap (Shift-OR)</em></b>

## Theory of numbers

In mathematics, the greatest common divisor (GCD) of two or more integers, which are not all zero, is the largest positive integer that divides each of the integers. For two integers x, y, the greatest common divisor of x and y is denoted gcd(x, y). For example, the GCD of 8 and 12 is 4.
Currently available algorithms:
* <b><em>Euclidean algorithm.</em></b>
* <b><em>Stein's algorithm</em></b>
---
A prime number (or a prime) is a natural number greater than 1 that is not a product of two smaller natural numbers. A natural number greater than 1 that is not prime is called a composite number.
Currently available algorithms:
* <b><em>Eratosthenes sieve.</em></b> 
* <b><em>Sundaram sieve</em></b> 
---
* <b><em>Fibonacci.</em></b>  
---
* <b><em>Factorial.</em></b>

## Elementary functions

Exponentiation is a mathematical operation, written as b^n, involving two numbers, the base b and the exponent or power n. It is pronounced as "b raised to the power of n". When n is a positive integer, exponentiation corresponds to repeated multiplication of the base: that is, b^n is the product of multiplying bases n-times.
Currently available algorithms:
* <b><em>Exponentiation Squaring</em></b>
* <b><em>Naive exponentiation.</em></b>
---
Summation of sequence.
Currently available algorithms:
* <b><em>Kahan summation algorithm</em></b>
* <b><em>Naive summation algorithm</em></b>
---
* <b><em>Gauss–Legendre algorithm</em></b>
* <b><em>Borwein algorithm</em></b>
* <b><em>Chudnovsky algorithm</em></b>
=======
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
>>>>>>> repob/main
=======
# Graph algorithms

Comparison of minimal spanning tree and shortest path algorithms

* Version 1.1

## Shortest path on graph

In graph theory, the shortest path problem is the problem of finding a path between two vertices (or nodes) in a graph such that the sum of the weights of its constituent edges is minimized. The problem of finding the shortest path between two intersections on a road map may be modeled as a special case of the shortest path problem in graphs, where the vertices correspond to intersections and the edges correspond to road segments, each weighted by the length of the segment.

Currently available algorithms:

* <b><em>Dijkstra's algorithm</b></em> is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks. It was conceived by computer scientist Edsger W. Dijkstra in 1956 and published three years later.
* <b><em>Floyd–Warshall algorithm.</b></em> In computer science, the Floyd–Warshall algorithm (also known as Floyd's algorithm, the Roy–Warshall algorithm, the Roy–Floyd algorithm, or the WFI algorithm) is an algorithm for finding shortest paths in a directed weighted graph with positive or negative edge weights (but with no negative cycles).
* <b><em>Johnson's algorithm</b></em> is a way to find the shortest paths between all pairs of vertices in an edge-weighted directed graph. It allows some of the edge weights to be negative numbers, but no negative-weight cycles may exist. It works by using the Bellman–Ford algorithm to compute a transformation of the input graph that removes all negative weights, allowing Dijkstra's algorithm to be used on the transformed graph.

## Minimum spanning tree

A minimum spanning tree (MST) or minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight. That is, it is a spanning tree whose sum of edge weights is as small as possible. More generally, any edge-weighted undirected graph (not necessarily connected) has a minimum spanning forest, which is a union of the minimum spanning trees for its connected components.

Currently available algorithms:

* <b><em>Kruskal's algorithm</b></em> finds a minimum spanning forest of an undirected edge-weighted graph. If the graph is connected, it finds a minimum spanning tree. (A minimum spanning tree of a connected graph is a subset of the edges that forms a tree that includes every vertex, where the sum of the weights of all the edges in the tree is minimized. For a disconnected graph, a minimum spanning forest is composed of a minimum spanning tree for each connected component.) It is a greedy algorithm in graph theory as in each step it adds the next lowest-weight edge that will not form a cycle to the minimum spanning forest.
* <b><em>Prim's algorithm.</b></em> In computer science, Prim's algorithm (also known as Jarník's algorithm) is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized. The algorithm operates by building this tree one vertex at a time, from an arbitrary starting vertex, at each step adding the cheapest possible connection from the tree to another vertex.
* <b><em>Reverse-delete algorithm.</b></em>The reverse-delete algorithm is an algorithm in graph theory used to obtain a minimum spanning tree from a given connected, edge-weighted graph. It first appeared in Kruskal (1956), but it should not be confused with Kruskal's algorithm which appears in the same paper.
>>>>>>> repoc/main
