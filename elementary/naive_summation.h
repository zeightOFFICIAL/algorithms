// naive_summation.h

#include <vector> // vector

template <typename T> T NaiveSumRecursive(std::vector<T> elements);
template <typename T> T NaiveSumIterative(std::vector<T> elements);

/*
    (vector T A)->(T B)
    Finds the sum of elements in vector A.
    Returns B.
*/
template <typename T> T NaiveSumRecursive(std::vector<T> elements) {
  if (elements.size() == 1)
    return elements[0];
  T value = elements[elements.size() - 1];
  elements.pop_back();
  return value + NaiveSumRecursive(elements);
}

template <typename T> T NaiveSumIterative(std::vector<T> elements) {
  T result = 0;
  for (T value : elements)
    result = result + value;
  return result;
}