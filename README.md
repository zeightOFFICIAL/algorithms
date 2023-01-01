# Algorithms
## Sorting
* <strong>Bubble sort</strong> - is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order. This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high
* <strong>Comb sort</strong> - is mainly an improvement over Bubble Sort. Comb Sort improves on Bubble Sort by using a gap of the size of more than 1. The gap starts with a large value and shrinks by a factor of 1.3 in every iteration until it reaches the value 1. Thus Comb Sort removes more than one inversion count with one swap and performs better than Bubble Sort. The shrink factor has been empirically found to be 1.3. Although it works better than Bubble Sort on average, worst-case remains O(n2).
* <strong>Shell sort</strong> - is mainly a variation of Insertion Sort. The idea of ShellSort is to allow the exchange of far items. In Shell sort, we make the array h-sorted for a large value of h. We keep reducing the value of h until it becomes 1. An array is said to be h-sorted if all sublists of every h’th element are sorted.
* <strong>Cocktail sort</strong> - is a variation of Bubble sort. Cocktail Sort traverses through a given array in both directions alternatively. Cocktail sort does not go through the unnecessary iteration making it efficient for large arrays.
* <strong>Insertion sort</strong> - is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.
* <strong>Gnome sort</strong> - also called Stupid sort is based on the concept of a Garden Gnome sorting his flower pots. A garden gnome sorts the flower pots by the following method. He looks at the flower pot next to him and the previous one; if they are in the right order he steps one pot forward, otherwise he swaps them and steps one pot backwards. If there is no previous pot (he is at the starting of the pot line), he steps forwards; if there is no pot next to him (he is at the end of the pot line), he is done.
* <strong>Heap sort</strong> - is a comparison-based sorting technique based on Binary Heap data structure. It is similar to the selection sort where we first find the minimum element and place the minimum element at the beginning. Repeat the same process for the remaining elements. Heap sort is an in-place algorithm. Its typical implementation is not stable, but can be made stable. Typically 2-3 times slower than well-implemented QuickSort.  The reason for slowness is a lack of locality of reference.
<br><br>https://www.geeksforgeeks.org/
## Hashing
* <strong>adler32</strong>
* <strong>fnv132</strong>
* <strong>fnv164</strong>
* <strong>sha1</strong>
* <strong>sha256</strong>
## Pattern search
* <strong>Bitap</strong>
* <strong>Boyer-Moore</strong>
* <strong>Knuth-Morris-Pratt</strong>
* <strong>Rabin-Karp</strong>
* <strong>Naive</strong>
## Shortest path on graph
* <strong>Dijkstra</strong>
* <strong>Floyd-Warshall</strong>
* <strong>Johnson</strong>
## Minimum spanning tree on graph
* <strong>Kruskal</strong>
* <strong>Prim</strong>
* <strong>Reverse-Delete</strong>
## Elementary
* <strong>Naive exponentiation</strong> - is a simple method to calculate the first number (base) to the power of the second number (power). It multiples the base and current result step by step, eventually approaching the solution.
* <strong>Squaring exponentiation</strong> - is a general method for fast computation of large positive integer powers of a number, or more generally of an element of a semigroup, like a polynomial or a square matrix.
---
* <strong>Naive summation</strong> - is the addition of a sequence of any kind of numbers, called addends or summands; the result is their sum or total. Beside numbers, other types of values can be summed as well: functions, vectors, matrices, polynomials and, in general, elements of any type of mathematical objects on which an operation denoted "+" is defined.
* <strong>Kahan summation</strong> - is used to minimize the loss of significance in the total result obtained by adding a sequence of finite-precision floating-point numbers. This is done by keeping a separate running compensation (a variable to accumulate small errors).
<br><br>https://www.geeksforgeeks.org/
<br>https://en.wikipedia.org/
## Theory of numbers
* <strong>Factorial</strong> - is the multiplication of all positive integers smaller than or equal to n. For example factorial of 6 is 6 * 5 * 4 * 3 * 2 * 1 which is 720. 
* <strong>Fibonacci</strong> - is a number sequence. 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ... In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation: F(n) = F(n-1) + F(n-2). Last number of the presented above sequence is calculated as follows 144 = 89 + 55. 
---
* <strong>Stein GCD</strong> - is an algorithm that computes the greatest common divisor of two non-negative integers. Stein’s algorithm replaces division with arithmetic shifts, comparisons, and subtraction.
* <strong>Euclidean GCD</strong> - is a way to find the greatest common divisor of two positive integers. GCD of two numbers is the largest number that divides both of them. A simple way to find GCD is to factorize both numbers and multiply common prime factors.
---
* <strong>Eratosthenes primes sieve</strong> - given a number n, print all primes smaller than or equal to n. It is also given that n is a small number. 
* <strong>Sundaram primes sieve</strong> - given a number n, print all primes smaller than or equal to n. Uses a different mapping method than Eratosthenes sieve.
---
* <strong>Borwein Pi</strong> - is an algorithm devised by Jonathan and Peter Borwein to calculate the value of 1/pi. They devised several other algorithms. They published the book Pi and the AGM – A Study in Analytic Number Theory and Computational Complexity.
* <strong>Chudnovsky Pi</strong> - is a fast method for calculating the digits of pi, based on Ramanujan’s pi formulae. It was published by the Chudnovsky brothers in 1988. It was used in the world record calculations of 2.7 trillion digits of pi in December 2009, 10 trillion digits in October 2011, 22.4 trillion digits in November 2016, 31.4 trillion digits in September 2018–January 2019, 50 trillion digits on January 29, 2020, 62.8 trillion digits on August 14, 2021, and 100 trillion digits on March 21, 2022.
* <strong>Gauss-Legendre Pi</strong> - is an algorithm to compute the digits of pi. It is notable for being rapidly convergent, with only 25 iterations producing 45 million correct digits of pi.
<br><br>https://www.geeksforgeeks.org/
<br>https://en.wikipedia.org/