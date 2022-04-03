# String-searching algorithms
Comparison of string-searching algorithms

* Version 1.18

In computer science, string-searching algorithms, sometimes called string-matching algorithms, are an important class of string algorithms that try to find a place where one or several strings (also called patterns) are found within a larger string or text.

Currently available algorithms:

| Algorithm | Type | Complexity in worst case | Complexity in best case |
| :---:                 | :---:               | :---:  | :---:  |
| Naive                 | Simple indexing     | O(2*m)  | O(m+n)  |
| Boyer-Moore (1977)    | Bad char heuristics | O(m+n+sigma)  | O(n)   | 
| Rabin-Karp (1987)     | Hashing             | O(mn)  | O(m+n) |
| Bitap (1964) Shift-OR | Uses features of circular bit shift and linearizability of bitwise OR and SHIFT | O(mn) | O(m+n) |

---
## Test results (random symbols)
The power of alphabet is 63 symbols (upper, lower-case latin, numbers). Length is adjustible. Searched pattern is 'ab'.

| Length of string (n)| Boyer-Moore (s) | Rabin-Karp (s) | Naive algorithm (s)| Bitap (s)|
|:---:|:---:|:---:|:---:|:---:|
|1000 |0.000016 |0.00002 |0.000016 |0.000035
|5000 |0.000083 |0.00008 |0.000084 |0.000059
|10000 |0.000152 |0.000145 |0.000183 |0.000109
|25000 |0.000293 |0.000407 |0.000467 |0.000332
|50000 |0.000652 |0.000863 |0.001007 |0.000431
|75000 |0.000934 |0.001394 |0.001467 |0.000783
|100000 |0.00127 |0.001856 |0.001987 |0.000935
|150000 |0.001977 |0.00257 |0.003029 |0.001325
|200000 |0.002553 |0.003394 |0.003995 |0.001949
|250000 |0.00312 |0.004568 |0.005032 |0.002505
|500000 |0.006132 |0.008962 |0.010223 |0.004936