# Sorting algorithms
Comparison of sorting algorithms

* Version 1.2

In computer science, a sorting algorithm is an algorithm that puts elements of a list into an order. The most frequently used orders are numerical order and lexicographical order, and either ascending or descending. Efficient sorting is important for optimizing the efficiency of other algorithms (such as search and merge algorithms) that require input data to be in sorted lists. Sorting is also often useful for canonicalizing data and for producing human-readable output.

Currently available algorithms:

|Algorithm|Type|Complexity in worst case|Complexity in best case|Stable|
|:---:|:---:|:---:|:---:|:---:|
|Bubble sort|Comparison of neighbors (exchanging)|O(n^2)|O(n)|Yes|
|Heap sort|Comparison of parent and child (selection)|O(n log(n))|O(n log(n))|No|
|Insertion sort|Comparison of the row (insertion)|O(n^2)|O(n)|Yes|
|Gnome sort|Comparison of the row (exchanging)|O(n^2)|O(n)|Yes|
|Stooge sort|Comparison of first and last (exchanging)|O(n^(log(3)/log(1.5)))|O(n^(log(3)/log(1.5)))|No|

Stable sort algorithms sort equal elements in the same order that they appear in the input.

---
## Test results
Truly random row of numbers. For some algorithms this is the best case, for others average or even worse. Which means that we cannot properly estimate efficiency ever. 

|Number of elements (n)|Bubble sort (s)|Heap sort (s)|Insertion sort (s)|Gnome sort(s)|Stooge sort (s)|
|:---:|:---:|:---:|:---:|:---:|:---:|
|100|0.0000524|0.0000334|0.0000111|0.0000428||0.003011|
|250|0.0003035|0.0000984|0.0000639|0.00028|0.0339093|
|500|0.0012558| 0.0002574|0.0002615|0.0010717|0.2829266|
|1000|0.00525827|0.00055387|0.00099753|0.00439733|0.77392995|
|2500|0.0349408|0.0015168|0.0058465|0.0279343|20.4435662|
|5000|0.1902329|0.0034712|0.0261482|0.1225653|74.296109|
|10000|0.6656259|0.0068431|0.0913343|0.4457501|359.23095|
|25000|4.3721741|0.0207328|0.5841881|2.714359|?6000|
|50000|17.877673|0.041827|2.304975|10.760434|?36000|
|75000|39.785214|0.071666|5.579577|24.945645|?100000|
|100000|70.872735|0.091089|9.431447|45.539161|?225000|
|150000|158.558872|0.142775|22.109589|100.686872|?700000|