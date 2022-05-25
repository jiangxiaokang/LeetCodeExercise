#include "sort/SelectSort.h"
#include <vector>
#include <iostream>
#include "sort/BubbleSort.h"
#include "sort/InsertSort.h"

std::vector<int> GetRandomVec(int max_num,int count);

int main(){
    {
        SelectSort ss;
        std::vector<int> a = GetRandomVec(100,10);
        ss.DoSort(a);
    }
    {
        BubbleSort bs;
        std::vector<int> a = GetRandomVec(100,10);
        bs.DoSort(a);
    } 
    {
        InsertSort is;
        std::vector<int> a = GetRandomVec(100,10);
        is.DoSort(a);
    }  
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