#include <vector>
#include <algorithm>
#include "auxiliary.h"

/*
    (T* A, unsigned long B)->()
    Takes an array A (type T) with length of B and sorts it in 
    the ascending order, using bucket sorting. 
    Changes the array given as argument.
    >>BucketSort(unsorted array, amount of elements)
*/
//template <typename T>
void BucketSort(long long* array, long long amount_of_elements)  {
    std::vector<long long> bucket[amount_of_elements];
   for(auto i = 0; i<amount_of_elements; i++)  {          //put elements into different buckets
      bucket[int(amount_of_elements*array[i])].push_back(array[i]);
   }
   for(auto i = 0; i<amount_of_elements; i++) {
      sort(bucket[i].begin(), bucket[i].end());       //sort individual vectors
   }
   int index = 0;
   for(auto i = 0; i<amount_of_elements; i++) {
      while(!bucket[i].empty()) {
         array[index++] = *(bucket[i].begin());
         bucket[i].erase(bucket[i].begin());
      }
   }
}
    
    
    
    

    //for (auto each_bucket = 0; each_bucket < amount_of_elements-1; each_bucket++)
    //    sort(buckets[each_bucket].begin(), buckets[each_bucket].end());
    //array = NULL;
    //unsigned long index;
    //for (auto each_bucket = 0; each_bucket < amount_of_elements-1; each_bucket++)
    //    for (auto each_element = 0; each_element < buckets[each_bucket].size(); each_element++)
    //        array[index++] = buckets[each_bucket][each_element];
}