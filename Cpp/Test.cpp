//
// Created by zhouqi on 2023/8/27.
//

#include "Test.h"
#include "Sort.h"
#include <random>

namespace Algorithm {
vector<int> Test::generateRandomVector(size_t length) {
  vector<int> randomVector;
  randomVector.resize(length);

//  for (int i = 0; i < length; ++i) {
//    randomVector[i] = rand();
//  }

  std::random_device rd;  // 使用硬件熵作为随机数种子
  std::mt19937 gen(rd()); // 使用Mersenne Twister随机数引擎
  std::uniform_int_distribution<> dis(
      1, INT_MAX); // 生成1到100之间的均匀分布的整数
  for (int i = 0; i < length; ++i) {
    randomVector[i] = dis(gen);
  }

//  std::default_random_engine engine;
//  for (int i = 0; i < length; ++i) {
//    randomVector[i] = engine();
//  }

  return randomVector;
}
void Test::printVector(const vector<int> &variables) {
  std::cout << "printVector start" << std::endl;
  for (int v : variables) {
    std::cout << v << ' ';
  }
  std::cout << std::endl << "printVector end" << std::endl;
}
} // namespace Algorithm
int main() {
  using Algorithm::Test;
  std::cout << "Hello world!" << std::endl;

#ifdef INSERTION_SORT_TEST
  using Algorithm::Sort::InsertionSort;
  size_t testLength1 = 900;
  vector<int> &&randomVector1 = Test::generateRandomVector(testLength1);
  Test::isVectorSorted(randomVector1);
  // Test::printVector(randomVector1);
  InsertionSort(randomVector1);
  // Test::printVector(randomVector1);
  Test::isVectorSorted(randomVector1);
#endif
#ifdef MERGESORT_TEST
  using Algorithm::Sort::MergeSort;
  size_t testLength2 = 9000;
  vector<int> &&randomVector2 = Test::generateRandomVector(testLength2);
  Test::isVectorSorted(randomVector2);
  // Test::printVector(randomVector1);
  MergeSort(randomVector2, 0, randomVector2.size());
  Test::printVector(randomVector2);
  Test::isVectorSorted(randomVector2);
#endif
#ifdef BUBBLESORT_TEST
  using Algorithm::Sort::BubbleSort;
  size_t testLength3 = 2000;
  vector<int> &&randomVector3 = Test::generateRandomVector(testLength3);
  Test::isVectorSorted(randomVector3);
  // Test::printVector(randomVector1);
  BubbleSort(randomVector3);
  //Test::printVector(randomVector3);
  Test::isVectorSorted(randomVector3);
#endif
  return 0;
}