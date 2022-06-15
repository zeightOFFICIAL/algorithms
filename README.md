# String-searching algorithms
Comparison of string-searching algorithms

* Version 1.195

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
|5000|1.48e-05|6.58e-05|9.34e-06|7.23e-06|
|10000|3.17e-05|8.234e-05|1.667e-05|1.171e-05|
|25000|7.732e-05|0.00020851|5.972e-05|3.268e-05|
|50000|0.00017781|0.00082422|0.00010862|6.987e-05|
|75000|0.00034365|0.00124158|0.00018071|0.0001102|
|100000|0.00040399|0.00191754|0.00021328|0.00018046|
|150000|0.00066402|0.00327804|0.00032508|0.00060955|
|200000|0.00170389|0.00352574|0.00043065|0.00068235|
|250000|0.00270992|0.00397704|0.00100534|0.00084813|
|500000|0.00360309|0.01005229|0.00207496|0.00095416|