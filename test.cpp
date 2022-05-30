#include "sort/SelectSort.h"
#include <vector>
#include <iostream>
#include "sort/SortHeader.h"
#include "code/binary_search/findPeakElement.h"
#include "code/priority_queue.h"
#include "code/reverseList.h"
#include "code/reverseDoubleList.h"
#include "code/isPalindrome.h"
#include "code/partitionList.h"

std::vector<int> GetRandomVec(int max_num,int count);

int main(){
    // {
     //   std::vector<int> a = GetRandomVec(1000,10000);
    //     MergeSort().DoSort(a);
    //     InsertSort()s.DoSort(a);
    //     BubbleSort().DoSort(a);
        // SelectSort().DoSort(a);
       // QuickSort().DoSort(a);
        //QuickSort2().DoSort(a);
        // HeapSort().DoSort(a);
        // RadixSort().DoSort(a);
        //SortBase::StdSort(a);
    // }
    // FindPeakElementTest test;
    // std::vector<int> a= {1,2,3,4,3};
    // std::cout<<test.findPeakElement(a)<<std::endl;
    //TEST::TestPriorityQueue();
    //Solution206().test();
    //SolutionDoubleLinkList().test();
    //SolutionIsPalindrome().test();
    SolutionPartitionList().test();

    return 0;
}

std::vector<int> GetRandomVec(int max_num,int count){
    std::vector<int> vec;
    while(count>0){
        vec.push_back(std::rand()%max_num);
        count--;
    }
    return vec;
}