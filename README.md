# Sorting algorithms
Comparison of sorting algorithms

* Version 1.19

In computer science, a sorting algorithm is an algorithm that puts elements of a list into an order. The most frequently used orders are numerical order and lexicographical order, and either ascending or descending. Efficient sorting is important for optimizing the efficiency of other algorithms (such as search and merge algorithms) that require input data to be in sorted lists. Sorting is also often useful for canonicalizing data and for producing human-readable output.

Currently available algorithms:

|Algorithm|Type|Complexity in worst case|Complexity in best case|
|:---:|:---:|:---:|:---:|
|Bubble sort|Comparison of neighbors (exchanging)|O(n^2)| O(n) |
|Heap sort|Comparison of parent and child (selection)| O(n log(n)) | O(n log(n))| 
|Insertion sort|Comparison of the row (insertion)|O(n^2)|O(n)|
|Stooge sort|Comparison of first and last (exchanging)|O(n^(log(3)/log(1.5)))|O(n^(log(3)/log(1.5)))|

---
## Test results
Truly random row of numbers. For some algorithms this is the best case, for others average or even worse. Which means that we cannot properly estimate efficiency ever. 

|Number of elements (n)|Bubble sort (s)|Heap sort (s)|Insertion sort (s)|Stooge sort (s)|
|:---:|:---:|:---:|:---:|:---:|
|100|0.0000326|0.000014|0.0000082|0.0019499 |
|250|0.0001929|0.0000372|0.00005|0.0175228|
|500|0.000745|0.000084|0.000168|0.202|
|1000|0.0036358|0.0002088|0.0007176|0.45|
|2500|0.0239991|0.000562|0.0043637|12.351|
|5000|0.089812|0.001192|0.017059|39.345|
|10000|0.387319|0.002664|0.069054|334.601|
|25000|2.37357|0.007|0.42354|6000|
|50000|9.53622|0.0153|1.68284|36000|
|75000|21.6597|0.0252|4.169|100000|
|100000|35.9244|0.033|7.6735|225000|
|150000|85.8114|0.0573|16.7438|700000|
