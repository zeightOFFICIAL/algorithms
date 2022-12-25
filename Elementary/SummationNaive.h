// SummationNaive.h

#include <vector>

namespace summation {
  /*
    (vector T A) -> (T B)
    Finds the sum of elements in vector A. Uses recursion.
    Returns B.
  */
  template <typename T> static T naiveRecursiveSummation(std::vector<T> elements);
  /*
    (vector T A) -> (T B)
    Finds the sum of elements in vector A. Uses iteration.
    Returns B.
  */
  template <typename T> static T naiveIterativeSummation(std::vector<T> elements);
  
  template <typename T> static T naiveRecursiveSummation(std::vector<T> elements) {
    if (elements.size() == 1) {
      return elements[0];
    }
    
    T value = elements[elements.size() - 1];
    elements.pop_back();
  
    return value + naiveRecursiveSummation(elements);
  }
  template <typename T> static T naiveIterativeSummation(std::vector<T> elements) {
    if (elements.size() == 1) {
      return elements[0];
    }
    T result = 0;
  
    for (T value : elements) {
      result = result + value;
    }
  
    return result;
  }
} // namespace summation