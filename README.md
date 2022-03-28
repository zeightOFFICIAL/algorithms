# String-searching algorithms
Comparison of string-searching algorithms

* Version 1.17

In computer science, string-searching algorithms, sometimes called string-matching algorithms, are an important class of string algorithms that try to find a place where one or several strings (also called patterns) are found within a larger string or text.

Currently available algorithms:

| Algorithm | Type | Complexity in worst case | Complexity in best case |
| :---:              | :---:               | :---:  | :---:  |
| Naive              | Simple indexing     | O(mn)  | O(mn)  |
| Boyer-Moore (1977) | Bad char heuristics | O(mn)  | O(n)   | 
| Rabin-Karp (1987)  | Hashing             | O(mn)  | O(m+n) |

---
## 1.1 Test with random string
- The power of alphabet is 63 symbols (upper, lower-case latin, numbers)
- Length is adjustible
- Searched pattern is ('ab')

| Length of string (n)   | Boyer-Moore (s) | Rabin-Karp (s)  | Naive algorithm (s)|
|     :---:              |     :---:       |     :---:       |       :---:        |
| 1000                   |     0.000005	   |     0.000010	 |       0.000004     |         
| 5000                   |     0.000019	   |     0.000042	 |       0.000009     |   
| 10000                  |     0.000036	   |     0.000083	 |       0.000019     |   
| 25000                  |     0.000091	   |     0.000218	 |       0.000043     |   
| 50000                  |     0.000175	   |     0.000422	 |       0.000082     |   
| 75000                  |     0.000281	   |     0.000676	 |       0.000131     |   
| 100000                 |     0.000361	   |     0.000851	 |       0.000162     |   
| 150000                 |     0.000508	   |     0.001233	 |       0.000205     |   
| 200000                 |     0.000732	   |     0.001701	 |       0.000347     |