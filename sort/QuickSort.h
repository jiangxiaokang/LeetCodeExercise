#pragma once
/*
    不稳定排序

*/
#include "SortCommon.h"

class QuickSort : public SortBase
{
protected:
    virtual void Sort(std::vector<int>& vec) {
        Quick3(vec);
    }

    virtual void PrintSortName() {
        std::cout<<" Quick Sort " <<std::endl;
    }

    void Quick1(std::vector<int>& vec){
        // num = n-1
        // partition : <= num , > num
        // O(N^2)
    }
    void Quick2(std::vector<int>& vec){
        //num = n-1
        // partition : < num , == num  , < num
        // O(N^2)
    }
    void Quick3(std::vector<int>& vec){
        //compare num  = random
        //O(NlogN)
        Process(vec,0, vec.size() - 1);
    }
    std::tuple<int,int> partition(std::vector<int>& vec, int l , int r ){
        int less = l-1;//小于比较值的右边界
        int more = r;
        //vec[r]用来比较的值
        while(l < more){
            if(vec[l] < vec[r]){
                less++;
                SwapPos(vec, less, l);
                l++;
            }
            else if(vec[l] > vec[r]){
                SwapPos(vec,--more,l);
            }
            else{
                //相等
                l++;
            }
        }
        SwapPos(vec,more,r);
        //返回小于区域右边界，大于区域左边界
        return std::make_tuple(less + 1 , more);
    }

    void Process(std::vector<int>& vec, int l ,int r){
        if(l>=r){
            return;
        }
        int randPos = std::rand() % (r - l + 1) + l;
        SwapPos(vec, randPos, r);
        std::tuple<int,int> tup = partition(vec, l, r);
        Process(vec, l, std::get<0>(tup) - 1);
        Process(vec, std::get<1>(tup) + 1, r);
    }
};