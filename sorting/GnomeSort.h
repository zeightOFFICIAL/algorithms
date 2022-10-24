// GnomeSort.h

/*
Gnome Sort also called Stupid sort is based on the concept of a
Garden Gnome sorting his flower pots. A garden gnome sorts the
flower pots by the following method:
 - He looks at the flower pot next to him and the previous one;
if they are in the right order he steps one pot forward, otherwise
he swaps them and steps one pot backwards.
 - If there is no previous pot (he is at the starting of the pot line),
he steps forwards; if there is no pot next to him (he is at the end of the pot
line), he is done. 

https://www.geeksforgeeks.org/gnome-sort-a-stupid-one/
*/

/*
  (T* A, unsigned long B, bool C) -> ()
  Takes an array A (type T) with length of B and sorts it in
  the ascending order if C - true and descending if C - false,
  using gnome sorting (a.k.a stupid sort)
  -Changes the array given as argument.
*/
template <typename T>
static void sortGnome(T *array, unsigned long length, bool order = true);

template <typename T>
static void sortGnome(T *array, unsigned long length, bool order) {
  unsigned long index = 1;
  unsigned long lastPosition = 2;
  if (order == true) {
    while (index < length) {
      if (array[index - 1] < array[index]) {
        index = lastPosition;
        lastPosition++;
      } else {
        std::swap(array[index - 1], array[index]);
        index--;
        if (index == 0) {
          index = lastPosition;
          lastPosition++;
        }
      }
    }
  } else if (order == false) {
    while (index < length) {
      if (array[index - 1] > array[index]) {
        index = lastPosition;
        lastPosition++;
      } else {
        std::swap(array[index - 1], array[index]);
        index--;
        if (index == 0) {
          index = lastPosition;
          lastPosition++;
        }
      }
    }
  }
}