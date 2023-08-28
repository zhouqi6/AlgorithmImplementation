//
// Created by zhouqi on 2023/8/27.
//

#ifndef ALGORITHMIMPLEMENTATION_TEST_H
#define ALGORITHMIMPLEMENTATION_TEST_H
#include "functional"
#include <iostream>
#include <vector>
using std::function;
using std::vector;
namespace Algorithm {

class Test {
public:
  static vector<int> generateRandomVector(size_t length);
  static void printVector(const vector<int> &);
  template <class T>
  static bool isVectorSorted(
      const vector<T> &ifSorted, bool needPrint = true,
      function<bool(const T &, const T &)> comparator = std::less<T>()) {
    using SizeT = decltype(ifSorted.size());
    for (SizeT i = 0; i + 1 < ifSorted.size();) {
      if (comparator(ifSorted[i], ifSorted[i + 1]) ||
          !comparator(ifSorted[i + 1], ifSorted[i])) {
        ++i;
      } else {
        std::cout << std::boolalpha << false << std::noboolalpha << std::endl;
        return false;
      }
    }
    std::cout << std::boolalpha << true << std::noboolalpha << std::endl;
    return true;
  }
};

} // namespace Algorithm

#endif // ALGORITHMIMPLEMENTATION_TEST_H
