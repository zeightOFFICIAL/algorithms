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
|5000|1.271e-05|2.762e-05|1.068e-05|7.67e-06|
|10000|2.76e-05|6.513e-05|1.966e-05|1.572e-05|
|25000|6.874e-05|0.0006023|4.603e-05|4.279e-05|
|50000|0.00013499|0.00078763|0.00056973|7.667e-05|
|75000|0.00026794|0.00110445|0.00014963|0.00013441|
|100000|0.00041738|0.00145867|0.00053912|0.0002919|
|150000|0.00093601|0.00116639 |0.00038264|0.00024067|
|200000|0.0010459|0.0032966|0.00041525|0.00031688|
|250000|0.00163997|0.00393613|0.00058088|0.00045765|
|500000|0.00324141|0.00726229|0.00171175|0.00071272|