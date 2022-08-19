# Recursive and iterative algorithms
Comparison of recursive and iterative algorithms

* Version 1.1

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

\* This actually makes GCD-tail recursive the only one to be more efficient than iterative alternative.

---
## Test results 

Number of terms is within range which upon call of a function might result in values out of uint64 range.

| Number of terms (n) | Fibonacci recursive (s) | Fibonacci tail-recursion* (s) | Fibonacci iterative (s) |
| :---: | :---: | :---: | :---: |
| 20 | 0.000029 | 0.00000048 | 0.00000048 |
| 25 | 0.000300 | 0.0000005 | 0.00000041 |
| 30 | 0.003588 | 0.00000058 | 0.00000057 |
| 35 | 0.040263 | 0.000001 | 0.00000063 |
| 40 | 0.443793 | 0.00000071 | 0.00000051 |
| 45 | 4.850731 | 0.0000005 | 0.0000006 |
| 50 | 55.06831 | 0.0000005 | 0.00000044 |
| 90 | 5000 | 0.00000062 | 0.00000057 |

| Number of terms (n) | Factorial tail-recursion* (s) | Factorial iterative (s) |
| :---: | :---: | :---: |
| 25 | 0.00000056 | 0.00000052 |
| 35 | 0.00000035 | 0.00000041 |
| 45 | 0.00000056 | 0.00000056 |
| 55 | 0.00000046 | 0.00000046 |
| 65 | 0.00000057 | 0.00000059 |

| X and Y (numbers) | GCD tail-recursion* (s) | GCD iterative (s) |
|:---: | :---: | :---: |
| 99998 and 2 | 0.000001 | 0.000059 |
| 900000 and 3000 | 0.00000048 | 0.00000086 |
| 1000000 and 2 | 0.00000052 | 0.00065689 |
| 9000000 and 3 | 0.00000058 | 0.00410127|
| 9999998 and 2 | 0.00000061 | 0.00650714 |
| 423896423432 and 56 | 0.000002 | 9.75128 |
| 99999999999 and 3 | 0.000002 | 44.5731 |
| 99999999998 and 2 | 0.000002 | 60.3619 |

| X and Y (numbers) | SUM tail-recursion* (s) | SUM iterative (s) |
|:---: | :---: | :---: |
|10 and 1000|1.3e-05|2.5e-06|
|100 and 10000|0.0001343|2.76e-05|
|80000 and 100000|0.0002821|6.25e-05|
|100000 and 140000|0.0005441|0.0001223|

\* this function uses tail-recursion
