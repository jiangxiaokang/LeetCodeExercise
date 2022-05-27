#include "sort/SelectSort.h"
#include <vector>
#include <iostream>
#include "sort/BubbleSort.h"
#include "sort/InsertSort.h"
#include "sort/MergeSort.h"
#include "code/binary_search/findPeakElement.h"

std::vector<int> GetRandomVec(int max_num,int count);

int main(){
    // {
    //     SelectSort ss;
    //     std::vector<int> a = GetRandomVec(100,10);
    //     ss.DoSort(a);
    // }
    // {
    //     BubbleSort bs;
    //     std::vector<int> a = GetRandomVec(100,10);
    //     bs.DoSort(a);
    // } 
    // {
    //     InsertSort is;
    //     std::vector<int> a = GetRandomVec(100,100);
    //     is.DoSort(a);
    // }  
    {
        std::vector<int> a = GetRandomVec(10000,10000);
        MergeSort ms;
        ms.DoSort(a);
        InsertSort is;
        is.DoSort(a);
        BubbleSort bs;
        bs.DoSort(a);
        SelectSort ss;
        ss.DoSort(a);
    }
    // FindPeakElementTest test;
    // std::vector<int> a= {1,2,3,4,3};
    // std::cout<<test.findPeakElement(a)<<std::endl;
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