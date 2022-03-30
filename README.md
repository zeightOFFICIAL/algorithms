# String-searching algorithms
Comparison of string-searching algorithms

* Version 1.18

In computer science, string-searching algorithms, sometimes called string-matching algorithms, are an important class of string algorithms that try to find a place where one or several strings (also called patterns) are found within a larger string or text.

Currently available algorithms:

| Algorithm | Type | Complexity in worst case | Complexity in best case |
| :---:                 | :---:               | :---:  | :---:  |
| Naive                 | Simple indexing     | O(mn)  | O(mn)  |
| Boyer-Moore (1977)    | Bad char heuristics | O(mn)  | O(n)   | 
| Rabin-Karp (1987)     | Hashing             | O(mn)  | O(m+n) |
| Bitap (1964) Shift-OR | Uses features of circular bit shift and linearizability of bitwise OR and SHIFT | O(mn) | O(mn) |

---
## Test results (random symbols)
The power of alphabet is 63 symbols (upper, lower-case latin, numbers). Length is adjustible. Searched pattern is 'ab'.

| Length of string (n)   | Boyer-Moore (s) | Rabin-Karp (s) | Naive algorithm (s)| Bitap (s)|
|     :---:              |     :---:       |     :---:      |       :---:        | :---:    |
| 1000                   |     0.000004	   |     0.000008	|       0.000002     | 0.000002 |        
| 5000                   |     0.000018	   |     0.000040	|       0.000012     | 0.000009 |   
| 10000                  |     0.000032	   |     0.000078	|       0.000019     | 0.000013 |
| 25000                  |     0.000083	   |     0.000218	|       0.000052     | 0.000036 | 
| 50000                  |     0.000159	   |     0.000429	|       0.000102     | 0.000102 |  
| 75000                  |     0.000244	   |     0.000664	|       0.000172     | 0.000119 |  
| 100000                 |     0.000322	   |     0.000873   |       0.000221     | 0.000151 |  
| 150000                 |     0.000471	   |     0.001295	|       0.000309     | 0.000208 |  
| 200000                 |     0.000648	   |     0.001821	|       0.000405     | 0.000277 |
| 500000                 |     0.001588    |     0.004364   |       0.001107     | 0.000762 |

## Test results (texts)
The power of alphabet is 256 symbols (all ASCII). Length, searched pattern are listed in the table below, as well as the source of the text.

| ID | Source           | Length            | Pattern | Occurrences   |
| :---:|     :---:        |      :---:        |     :---:        |       :---:  |
|1| String-searching algorithm - Wikipedia | 9066 | 'search' | 40 |
|2| Novel "Stand" by Stephen King  | 2659099 | 'the' | 30784* |
|3| Novel "Stand" by Stephen King  | 2659099 | 'Permacover' | 4 |
|4| Novel "Stand" by Stephen King  | 2659099 | 'He and Larry sat on the' | 1 |

\* Bitap algorithm found 30802 occurrences. It is rather caused by extended symbols which have the same ASCII number as the ones used in pattern.


| ID | Boyer-Moore (s) | Rabin-Karp (s)  | Naive algorithm (s)| Bitap (s) |
|     :---: |     :---:       |     :---:       |       :---:        | :---:     |
|1|     0.000010	   |     0.000069	|       0.000021     | 0.000012 |  
|2|     0.007588	   |     0.024341	|       0.008281     | 0.003993 |  
|3|     0.002258	   |     0.022370	|       0.005104     | 0.003811 | 
|4|     0.001874       |     0.024133   |       0.005210     | 0.003950 |
