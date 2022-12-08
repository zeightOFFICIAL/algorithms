// ShellSort.h

#include "Utils.h"
using namespace sorting;

static u_short A102549[] = {1, 4, 10, 23, 57, 132, 301, 701};
static u_short A108870[] = {1, 4, 9, 20, 46, 103};
static u_short A033622[] = {1, 5, 19, 41, 109};
static u_short A036562[] = {1, 8, 23, 77, 281};
static u_short A036569[] = {1, 3, 7, 21, 48, 112};
static u_short A003462[] = {1, 4, 13, 40, 121};
static u_short A003586[] = {1, 2, 3, 4, 6, 8, 9, 12};
static u_short A083318[] = {1, 3, 5, 9, 17, 33, 65};
static u_short A000225[] = {1, 3, 7, 15, 31, 63};

/*
(T *A, unsigned long B, bool C, Y D) -> ()
Takes an array A (type T) with length of B and sorts it in
the ascending order if C - true and descending if C - false,
using shell sorting with sequence D. Changes A, returns nothing.
*/
template <typename T, typename Y = u_short[8]>
static void sortShell(T *array, u_long length, bool order = true, Y &seq = A102549);

template <typename T, typename Y>
static void sortShell(T *array, u_long length, bool order, Y &seq) {
  for (u_short gap : seq) {
    for (u_long index = gap; index < length; index++) {
      T temp = array[index];
      u_long j;
      for (j = index; (j >= gap) && (array[j - gap] > temp); j -= gap) {
        array[j] = array[j - gap];
      }
      array[j] = temp;
    }
  }
  if (!order) {
    reverse(array, length);
  }
}