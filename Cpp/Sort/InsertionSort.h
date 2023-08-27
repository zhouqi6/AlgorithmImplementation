//
// Created by zhouqi on 2023/8/27.
//

#ifndef ALGORITHM_IMPLEMENTATION_INSERTION_SORT_H
#define ALGORITHM_IMPLEMENTATION_INSERTION_SORT_H
#include "functional"
#include <vector>
using std::function;
using std::vector;
namespace Algorithm {
namespace Sort {

template <typename T> class InsertionSort {
public:
  static void Sort(vector<T> &toSort,
            function<bool(const T &, const T &)> comparator = std::less<T>()) {
    size_t sortedPosition = 0;
    for (size_t unSortedPosition = sortedPosition + 1;
         unSortedPosition < toSort.size(); ++unSortedPosition) {
      T insertionVal = toSort[unSortedPosition];
      int insertionPos = sortedPosition;
      for (; insertionPos >= 0 &&
             comparator(insertionVal, toSort[insertionPos]);
           insertionPos--) {
        std::swap(toSort[insertionPos], toSort[insertionPos + 1]);
      }
      toSort[insertionPos + 1] = insertionVal;
      ++sortedPosition;
    }
  }
};

} // namespace Sort
} // namespace Algorithm

#endif // ALGORITHM_IMPLEMENTATION_INSERTION_SORT_H
