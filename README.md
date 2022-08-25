# Algorithms

The word Algorithm means ” A  set of rules to be followed in calculations or other problem-solving operations ” Or ” A procedure for solving a mathematical problem in a finite number of steps that frequently by recursive operations “. 

---
## Sorting
In computer science, a sorting algorithm is an algorithm that puts elements of a list into an order. The most frequently used orders are numerical order and lexicographical order, and either ascending or descending. Efficient sorting is important for optimizing the efficiency of other algorithms (such as search and merge algorithms) that require input data to be in sorted lists. Sorting is also often useful for canonicalizing data and for producing human-readable output.\
Currently available algorithms:

* <b><em>Bubble sort</em></b>, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.
* <b><em>Heap sort</em></b>, like selection sort, heapsort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element from it and inserting it into the sorted region.
* <b><em>Insertion sort</em></b> is a simple sorting algorithm that builds the final sorted array (or list) one item at a time.
* <b><em>Gnome sort</em></b>, nicknamed stupid sort, is a variation of the insertion sort sorting algorithm that does not use nested loops.
* <b><em>Stooge sort</em></b> is a recursive sorting algorithm. It is notable for its exceptionally bad time complexity.

|Algorithm|Type|Complexity in worst case|Complexity in best case|Stable|
|:---:|:---:|:---:|:---:|:---:|
|Bubble sort|Comparison of neighbors (exchanging)|$$O(n^2)$$|$$O(n)$$|Yes|
|Heap sort|Comparison of parent and child (selection)|$$O(n log(n))$$|$$O(n log(n))$$|No|
|Insertion sort|Comparison of the row (insertion)|$$O(n^2)$$|$$O(n)$$|Yes|
|Gnome sort|Comparison of the row (exchanging)|$$O(n^2)$$|$$O(n)$$|Yes|
|Stooge sort|Comparison of first and last (exchanging)|$$O(n^{log(3)/log(1.5)})$$|$$O(n^{log(3)/log(1.5)})$$|No|
|<img width=200/>|<img width=1000/>|
  
## Substring search
In computer science, string-searching algorithms, sometimes called string-matching algorithms, are an important class of string algorithms that try to find a place where one or several strings (also called patterns) are found within a larger string or text. A basic example of string searching is when the pattern and the searched text are arrays of elements of an alphabet.

Currently available algorithms:

* <b><em>Boyer-Moore</em></b> is an efficient string-searching algorithm that is the standard benchmark for practical string-search literature. It was developed by Robert S. Boyer and J Strother Moore in 1977.
* <b><em>Rabin-Karp</em></b> is a string-searching algorithm created by Richard M. Karp and Michael O. Rabin (1987) that uses hashing to find an exact match of a pattern string in a text. It uses a rolling hash to quickly filter out positions of the text that cannot match the pattern, and then checks for a match at the remaining positions.
* <b><em>Naïve algorithm</em></b> is a simple string-searching algorithm. It checks for all character of the main string to the pattern. Naive algorithm is exact string matching.
* <b><em>Bitap (Shift-OR)</em></b>, distinguishes itself from other well-known string searching algorithms in its natural mapping onto simple bitwise operations.

|Algorithm |Type|Matching time|
|:---:|:---:|:---:|
|Naive| Simple indexing, checks pattern and text one symbol at a time| $$O(nm)$$ in best: $$O(2m)$$|
|Boyer-Moore (1977)|Bad char heuristics, advanced naive algorithm| $$O(mn)$$ in best: $$O(m/n)$$|
|Rabin-Karp (1987)|Hashing, compare hash of pattern with hash of text| $$O(mn)$$|
|Bitap (1964) Shift-OR|Uses features of circular bit shift and linearizability of bitwise OR and SHIFT|$$O(m*(n/32))$$|
|<img width=300/>|<img width=1000/>|<img width=500/>|

## Recursion and Iteration
In computer science, recursion is a method of solving a computational problem where the solution depends on solutions to smaller instances of the same problem. Recursion solves such recursive problems by using functions that call themselves from within their own code. The approach can be applied to many types of problems, and recursion is one of the central ideas of computer science.

Iteration is the repetition of a process in order to generate a (possibly unbounded) sequence of outcomes. Each repetition of the process is a single iteration, and the outcome of each iteration is then the starting point of the next iteration. In mathematics and computer science, iteration (along with the related technique of recursion) is a standard element of algorithms.

Currently available algorithms:

* <b><em>Factorial</em></b> In mathematics, the factorial of a non-negative integer n, denoted by n!, is the product of all positive integers less than or equal to n. The factorial of n also equals the product of n with the next smaller factorial.
* <b><em>Fibonacci sequence</em></b> is a series of numbers in which each number is the sum of the two that precede it. Starting at 0 and 1, the sequence looks like this: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, and so on forever.
* <b><em>Greatest common divisor</em></b> In mathematics, the greatest common divisor (GCD) of two or more integers, which are not all zero, is the largest positive integer that divides each of the integers.
* <b><em>Sigma</em></b>, sum of all the elements within function in specific range.

|Function|Type|Complexity|
|:---:|:---:|:---:|
|Fibonacci|Iterative|$$O(n)$$|
|Fibonacci|Recursive|$$O(2^n)$$|
|Fibonacci|Tail-Recursive|$$O(n)$$|
|Factorial|Iterative|$$O(n)$$|
|Factorial|Tail-Recursive|$$O(n)$$|
|GCD*|Iterative|$$O(log(ab)$$|
|GCD*|Tail-Recursive|$$O(log(a+b)$$|
|SUM|Iterative|$$O(n)$$|
|SUM|Tail-Recursive|$$O(n)$$|
|<img width=300/>|<img width=1000/>|<img width=500/>|

\* This actually makes GCD-tail recursive the only one to be more efficient than iterative alternative.
