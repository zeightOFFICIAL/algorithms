# Sorting_algorithms
Comparison of sorting algorithms (by time and complexity) 

* Version 1.15

### main.cpp (iostream, fstream, random)
- Generate an array with truly random numbers
- Generate an array with custom numbers
- Generate an array with numbers from file
- Print a generated array in the console


### sortingalgorithms.cpp (iostream, fstream, ctime, string)
- Bubble sort
- Heap sort
- Insertion sort
-   Swap values using pointers function
-   Heapify (max heap) function
-   Write all the sorts by side in the file. In order examine their correct work
-   Write one particular array in the file

---
### Test results

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

| Time comparison |
|       :---:     |
| ![Screenshot from 2022-03-20 13 23 54](https://user-images.githubusercontent.com/50341618/159159898-ab00ac36-09a8-4dd3-b88a-f354eba14a54.png) |
