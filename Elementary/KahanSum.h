// SummationKahan.h

#include <vector>

namespace summation {
  /**
    (vector T A) -> (T B)
    Finds the sum of elements B in vector A. 
    Uses Kahan compensation. Returns B.
  */
  template <typename T> static T KahanSummation(std::vector<T> elements);
  
  template <typename T> static T KahanSummation(std::vector<T> elements) {
    if (elements.size() == 1) {
      return elements[0];
    }
    T result = 0.0, compensation = 0.0;
  
    for (T value : elements) {
      T valueCompensated = value - compensation;
      T resultCompensated = result + valueCompensated;
      compensation = (resultCompensated - result) - valueCompensated;
      result = resultCompensated;
    }
  
    return result;
  }
} // namespace summation