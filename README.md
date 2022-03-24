# Recursive and iterative algorithms
Comparison of recursion and iteration algorithms (by time and complexity)

* Version 1.04

### main.cpp (iostream, ctime)
- Enveloper for unary functions
- Enveloper for binary functions

### recursion_funcs.cpp
- Fibonacci recursive
- Factorial recursive
- GCD recursive

### iteration_funcs.cpp
- Fibonacci iterative
- Factorial iterative
- GCD iterative

---
### Test results

| Number of terms (n) | Fibonacci recursive (s) | Fibonacci tail-recursion* (s) | Fibonacci iterative (s) |
| :---: | :---: | :---: | :---: |
| 20 | 0.000029 | 0.000001 | 0.000001 |
| 25 | 0.000314 | 0.000001 | 0.000001 |
| 30 | 0.003526 | 0.000001 | 0.000002 |
| 35 | 0.037494 | 0.000001 | 0.000002 |
| 40 | 0.428458 | 0.000001 | 0.000002 |
| 45 | 5.178851 | 0.000002 | 0.000002 |
| 50 | 55.46831 | 0.000002 | 0.000002 |
| 90 | - | 0.000002 | 0.000002 |

| Number of terms (n) | Factorial recursive (s) | Factorial iterative (s) |
| :---: | :---: | :---: |
| 25 | 0.000001 | 0.000001 |
| 35 | 0.000001 | 0.000001 |
| 45 | 0.000001 | 0.000001 |
| 55 | 0.000001 | 0.000001 |
| 65 | 0.000001 | 0.000001 |

| X and Y (numbers) | GCD recursive* (s) | GCD iterative (s) |
|     :---:           |     :---:       |     :---:     |
| 900000 and 3000 | 0.000002 | 0.000002 |
| 1000000 and 2   | 0.000653 | 0.000002 |
| 9000000 and 3   | 0.004029 | 0.000002 |
| 9999998 and 2   | 0.006348 | 0.000002 |
| 423896423432 and 56 | 9.536998  | 0.000002 |
| 99999999999 and 3   | 45.129561 | 0.000003 |

\* this function uses tail-recursion