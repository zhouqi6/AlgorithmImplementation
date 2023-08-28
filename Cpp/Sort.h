//
// Created by zhouqi on 2023/8/28.
//

#ifndef ALGORITHMIMPLEMENTATION_SORT_H
#define ALGORITHMIMPLEMENTATION_SORT_H
#include "functional"
#include <vector>
using std::function;
using std::swap;
using std::vector;
namespace Algorithm {
namespace Sort {

template <typename T>
void InsertionSort(
    vector<T> &toSort,
    function<bool(const T &, const T &)> comparator = std::less<T>()) {
  size_t sortedPosition = 0;
  for (size_t unSortedPosition = sortedPosition + 1;
       unSortedPosition < toSort.size(); ++unSortedPosition) {
    T insertionVal = toSort[unSortedPosition];
    int insertionPos = sortedPosition;
    for (; insertionPos >= 0 && comparator(insertionVal, toSort[insertionPos]);
         insertionPos--) {
      swap(toSort[insertionPos], toSort[insertionPos + 1]);
    }
    toSort[insertionPos + 1] = insertionVal;
    ++sortedPosition;
  }
}

template <typename T>
void MergeSort(
    vector<T> &toSort, int left, int right,
    function<bool(const T &, const T &)> comparator = std::less<T>()) {
  if (left + 1 < right) {
    int half = (left + right) / 2;
    MergeSort(toSort, left, half, comparator);
    MergeSort(toSort, half, right, comparator);
    int leftEnd = half;
    int mergePos = left;
    while (left < leftEnd && half < right) {
      if (comparator(toSort[left], toSort[half])) {
        toSort[mergePos++] = toSort[left++];
      } else {
        toSort[mergePos++] = toSort[half++];
      }
    }
    while (left < leftEnd) {
      toSort[mergePos++] = toSort[left++];
    }
    while (half < right) {
      toSort[mergePos++] = toSort[half++];
    }
  } else {
    return;
  }
}
template <typename T>
void BubbleSort(
    vector<T> &toSort,
    function<bool(const T &, const T &)> comparator = std::less<T>()) {
  bool swapped = false;
  for (int i = 0; i < toSort.size(); ++i) {
    swapped = false;
    for (int j = i + 1; j < toSort.size(); ++j) {
      if (comparator(toSort[j], toSort[i])) {
        swap(toSort[j], toSort[i]);
        swapped = true;
      }
    }
    if(!swapped){
      return;
    }
  }
}
} // namespace Sort
} // namespace Algorithm
#endif // ALGORITHMIMPLEMENTATION_SORT_H
