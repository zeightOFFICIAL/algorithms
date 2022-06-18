# Sorting algorithms
Comparison of sorting algorithms

* Version 1.2

In computer science, a sorting algorithm is an algorithm that puts elements of a list into an order. The most frequently used orders are numerical order and lexicographical order, and either ascending or descending. Efficient sorting is important for optimizing the efficiency of other algorithms (such as search and merge algorithms) that require input data to be in sorted lists. Sorting is also often useful for canonicalizing data and for producing human-readable output.

Currently available algorithms:

* <b><em>Bubble sort</em></b>, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.
* <b><em>Heap sort</em></b>, like selection sort, heapsort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element from it and inserting it into the sorted region.
* <b><em>Insertion sort</em></b> is a simple sorting algorithm that builds the final sorted array (or list) one item at a time.
* <b><em>Gnome sort</em></b>, nicknamed stupid sort, is a variation of the insertion sort sorting algorithm that does not use nested loops.
* <b><em>Stooge sort</em></b> is a recursive sorting algorithm. It is notable for its exceptionally bad time complexity.


|Algorithm|Type|Complexity in worst case|Complexity in best case|Stable|
|:---:|:---:|:---:|:---:|:---:|
|Bubble sort|Comparison of neighbors (exchanging)|$$O(n^2)$$|$$O(n)$$|Yes|
|Heap sort|Comparison of parent and child (selection)|$$O(n log(n))$$|$$O(n log(n))$$|No|
|Insertion sort|Comparison of the row (insertion)|$$O(n^2)$$|$$O(n)$$|Yes|
|Gnome sort|Comparison of the row (exchanging)|$$O(n^2)$$|$$O(n)$$|Yes|
|Stooge sort|Comparison of first and last (exchanging)|$$O(n^{log(3)/log(1.5)})$$|$$O(n^{log(3)/log(1.5)})$$|No|

Stable sort algorithms sort equal elements in the same order that they appear in the input.

---
## Test results
Truly random row of numbers. For some algorithms this is the best case, for others average or even worse. Which means that we cannot properly estimate efficiency ever. 

|Number of elements (n)|Bubble sort (s)|Heap sort (s)|Insertion sort (s)|Gnome sort(s)|Stooge sort (s)|
|:---:|:---:|:---:|:---:|:---:|:---:|
|5000  |0.169380|0.0039464|0.0636747|0.1169927|95.104169|
|10000 |0.696705|0.0076096|0.2416921|0.4428097|889.781318|
|15000 |1.629335|0.0128825|0.5501042|1.0163521|9000|
|20000 |2.909907|0.0178283|1.0158202|1.8428383|90000|
|25000 |4.502916|0.0214045|1.5473548|2.8087664|900000|
|30000 |6.485974|0.0304547|2.2516294|4.0492812|9000000|
|35000 |8.925461|0.0310476|3.0632473|5.6760093|90000000|
|40000 |12.01087|0.0385744|4.1901552|7.2630641|900000000|
|45000 |14.82523|0.0416432|5.0432094|9.1704645|-|
|50000 |17.93979|0.0523771|6.0870189|11.011022|-|
|55000 |21.52095|0.0548245|7.3353995|13.658959|-|
|60000 |25.83364|0.0589905|9.5131325|16.697626|-|
|65000 |29.93867|0.0604905|10.405098|18.549615|-|
|70000 |34.92269|0.0644784|12.055852|21.525006|-|
|75000 |41.22662|0.0735925|14.395464|25.582655|-|
|80000 |47.64794|0.0961683|16.697779|29.683289|-|
|85000 |52.67518|0.1050295|18.917568|31.984009|-|
|90000 |60.68210|0.1088821|20.917302|36.557343|-|
|95000 |66.40575|0.1120105|22.577558|40.964867|-|
|100000|74.35371|0.1164231|25.004096|45.629682|-|

