# Recursive and iterative algorithms
Comparison of recursive and iterative algorithms

* Version 1.05

In computer science, recursion is a method of solving a computational problem where the solution depends on solutions to smaller instances of the same problem. Recursion solves such recursive problems by using functions that call themselves from within their own code. The approach can be applied to many types of problems, and recursion is one of the central ideas of computer science.

Iteration is the repetition of a process in order to generate a (possibly unbounded) sequence of outcomes. Each repetition of the process is a single iteration, and the outcome of each iteration is then the starting point of the next iteration. In mathematics and computer science, iteration (along with the related technique of recursion) is a standard element of algorithms.

Currently available algorithms:

| Function | Type | Complexity |
| :---: | :---:| :---: |
| Fibonacci | Iterative | O(n) |
| Fibonacci | Recursive | O(2^n) |
| Fibonacci | Tail-Recursive | O(n) |
| Factorial | Iterative | O(n) |
| Factorial | Tail-Recursive | O(n) |
| GCD | Iterative | O(log(ab) |
| GCD | Tail-Recursive | O(log(a+b) |

---
## Test results 

Number of terms is within values which upon call of a function will result in values within range of uint64.

| Number of terms (n) | Fibonacci recursive (s) | Fibonacci tail-recursion* (s) | Fibonacci iterative (s) |
| :---: | :---: | :---: | :---: |
| 20 | 0.000029 | 0.00000048 | 0.00000048 |
| 25 | 0.000300 | 0.0000005 | 0.00000041 |
| 30 | 0.003588 | 0.00000058 | 0.00000057 |
| 35 | 0.040263 | 0.000001 | 0.00000063 |
| 40 | 0.443793 | 0.00000071 | 0.00000051 |
| 45 | 4.850731 | 0.0000005 | 0.0000006 |
| 50 | 55.06831 | 0.0000005 | 0.00000044 |
| 90 | - | 0.00000062 | 0.00000057 |

| Number of terms (n) | Factorial tail-recursion* (s) | Factorial iterative (s) |
| :---: | :---: | :---: |
| 25 | 0.00000056 | 0.00000052 |
| 35 | 0.00000035 | 0.00000041 |
| 45 | 0.00000056 | 0.00000056 |
| 55 | 0.00000046 | 0.00000046 |
| 65 | 0.00000057 | 0.00000059 |

| X and Y (numbers) | GCD tail-recursive* (s) | GCD iterative (s) |
|:---: | :---: | :---: |
| 99998 and 2 | 0.000001 | 0.000059 |
| 900000 and 3000 | 0.00000048 | 0.00000086 |
| 1000000 and 2 | 0.00000052 | 0.00065689 |
| 9000000 and 3 | 0.00000058 | 0.00410127|
| 9999998 and 2 | 0.00000061 | 0.00650714 |
| 423896423432 and 56 | 0.000002 | 9.75128 |
| 99999999999 and 3 | 0.000002 | 44.5731 |
| 99999999998 and 2 | 0.000002 | 60.3619 |

\* this function uses tail-recursion