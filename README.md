# String_searching_algorithms
Comparison of string-searching algorithms (by time and complexity)

* Version 1.15

### main.cpp (iostream, random, cstring, fstream)
- Generate string (char[]) with truly random chars
- Create custom (user) string (char[])
  
- Print string (char[]) in the console
- Print result (int[]) in the console
- Write string (char[]) in the file

### substringalgorithms.cpp (iostream, fstream, ctime)
- Boyer-Moore
- Rabin-Karp
- Naive algorithm  
- Enveloper with custom text for each search algorithm
- Bad char heuristics function
- Max by value function
- Write every occurances in the file

---
## 1.1 Test with random string.
-The power of alphabet is 63 symbols (upper, lower-case latin, number)
-Length is adjustible
-Searched pattern is ('ab')

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

| Time comparison |
| :---: |
| ![Screenshot from 2022-03-21 14 52 33](https://user-images.githubusercontent.com/50341618/159264695-68fe01c6-8720-4ace-8846-ad6681244dfb.png)      |

---
## 1.2 Test with html page.
- The power of alphabet is 256 symbols (all ascii symbols)
- Length is dependable (3985 in processed part of the text)
- Text is part of wiki's page considering web-scraping

| Word (occurances)  | Boyer-Moore (s) | Rabin-Karp (s) | Naive algorihm (s) |
|     :---:              |     :---:       |     :---:       |       :---:        |
| the (42)     | 0.000017        | 0.000041       | 0.000017           |
| HTML (2)     | 0.000013        | 0.000037       | 0.000011           |               
