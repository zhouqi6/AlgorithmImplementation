//
// Created by zhouqi on 2023/8/27.
//

#include "Test.h"
#include "InsertionSort.h"

namespace Algorithm {
vector<int> Test::generateRandomVector(size_t length) {
    vector<int> randomVector;
    randomVector.resize(length);
    for(int i=0;i<length;++i){
      randomVector[i] = rand();
    }
    return randomVector;

}
void Test::printVector(const vector<int> &variables) {
    std::cout<<"printVector start"<<std::endl;
    for(int v:variables){
      std::cout<<v<<' ';
    }
    std::cout<<std::endl<<"printVector end"<<std::endl;
}
} // Algorithm
int main(){
    using Algorithm::Test;
    std::cout<<"Hello world!"<<std::endl;

#ifdef ALGORITHM_IMPLEMENTATION_INSERTION_SORT_TEST
    using Algorithm::Sort::InsertionSort;
    size_t testLength = 900;
    vector<int>&& randomVector = Test::generateRandomVector(testLength);
    Test::isVectorSorted(randomVector);
    //Test::printVector(randomVector);
    InsertionSort<int>::Sort(randomVector);
    //Test::printVector(randomVector);
    Test::isVectorSorted(randomVector);
#endif
    return 0;
}