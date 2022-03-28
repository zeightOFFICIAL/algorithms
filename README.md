# Sorting algorithms
Comparison of sorting algorithms

* Version 1.18

In computer science, a sorting algorithm is an algorithm that puts elements of a list into an order. The most frequently used orders are numerical order and lexicographical order, and either ascending or descending. Efficient sorting is important for optimizing the efficiency of other algorithms (such as search and merge algorithms) that require input data to be in sorted lists. Sorting is also often useful for canonicalizing data and for producing human-readable output.

Currently available algorithms:

| Algorithm | Type | Complexity in worst case | Complexity in best case |
| :---:              | :---:               | :---:  | :---:  |
| Bubble sort        | Comparison of neighbors (exchanging)       | n^2  | n |
| Heap sort          | Comparison of parent and child (selection) | n log(n) | n log(n) | 
| Insertion sort     | Comparison of the row (insertion)          | n^2  | n |

---
## Test results
Totally random row of numbers

| Number of elements (n) | Bubble sort (s) | Heap sort (s) | Insertion sort (s) |
|     :---:              |     :---:       |     :---:     |       :---:        |
| 100                    |     0.000008	   |     0.000004	 |       0.000004     |         
| 250                    |     0.000063	   |     0.000008	 |       0.000019     |   
| 500                    |     0.000255	   |     0.000021	 |       0.000098     |   
| 1000                   |     0.000857	   |     0.000081	 |       0.000344     |   
| 2500                   |     0.004525	   |     0.000212	 |       0.001758     |   
| 5000                   |     0.022087	   |     0.000501	 |       0.007695     |   
| 10000                  |     0.117118	   |     0.001097	 |       0.030569     |   
| 25000                  |     0.984493	   |     0.002588	 |       0.153553     |   
| 50000                  |     4.154143	   |     0.006633	 |       0.715004     |   
| 75000                  |     9.508223	   |     0.010001	 |       1.688823     |   
| 100000                 |     16.05213    |     0.013795  |       2.909558     |          
| 150000                 |     35.10996	   |     0.021923	 |       6.769227     |

![Screenshot from 2022-03-20 13 23 54](https://user-images.githubusercontent.com/50341618/159159898-ab00ac36-09a8-4dd3-b88a-f354eba14a54.png)