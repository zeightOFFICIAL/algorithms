# Sorting_algorithms
Comparison of sorting algorithms (by time and complexity) 

* Version 1.15

main.cpp (iostream, fstream, random)
- Generate an array with truly random numbers
- Generate an array with custom numbers
- Generate an array with numbers from file
- Print a generated array in the console


sortingalgorithms.cpp (iostream, fstream, ctime, string)
- Bubble sort
- Heap sort
- Insertion sort
- Swap values using pointers function
- Heapify (max heap) function
- Write all the sorts by side in the file. In order examine their correct work
- Write one particular array in the file

=================================================================================

| Number of elements (n) | Bubble sort (s) | Heap sort (s) | Insertion sort (s) |
|     :---:              |     :---:       |     :---:     |       :---:        |
| 100                    |     0.000008	   |     0.000004	 |       0.000004     |         
| 250                    |     0.000063	   |     0.000008	 |       0.000019     |   
| 500                    |     0.000255	   |     0.000021	 |       0.000098     |   
| 1000                   |     0.000857	   |     0.000080	 |       0.000344     |   
| 2500                   |     0.004925	   |     0.000232	 |       0.001758     |   
| 5000                   |     0.022087	   |     0.000501	 |       0.007695     |   
| 10000                  |     0.117118	   |     0.001097	 |       0.030569     |   
| 25000                  |     0.964493	   |     0.002988	 |       0.193553     |   
| 50000                  |     4.004143	   |     0.006833	 |       0.765004     |   
| 75000                  |     9.108223	   |     0.011001	 |       1.708823     |   
| 100000                 |     15.95213    |     0.014295  |       3.009558     |          
| 150000                 |     35.40996	   |     0.022923	 |       6.969227     |   

![Screenshot from 2022-03-20 13 23 54](https://user-images.githubusercontent.com/50341618/159159898-ab00ac36-09a8-4dd3-b88a-f354eba14a54.png)
