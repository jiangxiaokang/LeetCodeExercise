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

class QuickSort2: public SortBase
{
protected:

    virtual void Sort(std::vector<int>& vec) {
        Process2(vec,0, vec.size() -1);
    }

    virtual void PrintSortName() {
        std::cout<<" Quick Sort 2 " <<std::endl;
    }
    //<=num , > num
    int partition2(std::vector<int>& vec, int l , int r){
        int pivot = vec[r];
        // while(l < r){
        //     while(l < r && pivot <= vec[r]){
        //         --r;
        //     }
        //     vec[l] = vec[r];
        //     while(l < r && vec[l] <= pivot){
        //         ++l;
        //     }
        //     vec[r] = vec[l];
        // }
        // vec[l] = pivot;
        // return l;
        int index = r;
        while(l < r){
            if(pivot >= vec[l]){
                ++l;
            }
            else{
                //找到第一个大于pivot的位置，放到最后缩小范围
                --r;
                SwapPos(vec, l, r);
                //继续判断
            }
        }
        SwapPos(vec,index, l);
        return l;
    }

    void Process2(std::vector<int>& vec, int l ,int r){
        if(l>=r){
            return;
        }
        // int mid = l + (r-l)/2;
        // MoveMedianTo(vec, r, l , mid ,r-1);// 取l+1, m, r中的中位数放到r位
         int randPos = std::rand() % (r - l + 1) + l;
        SwapPos(vec, randPos, r);
        int pivot = partition2(vec, l, r);
        Process2(vec, l, pivot - 1);
        Process2(vec, pivot + 1, r);      
    }
    void MoveMedianTo(std::vector<int>& vec,int result , int a, int b ,int c)
    {
        //operator <
        if(vec[a] < vec[b])
        {
            if(vec[c] < vec[a]){
                SwapPos(vec, result, a);
            }
            else if(vec[b] < vec[c]){
                SwapPos(vec, result , b);
            }
            else{
                SwapPos(vec, result , c);
            }
        }
        else if(vec[a]< vec[c])//vec[b]<=vec[a]
        {
            SwapPos(vec, result , a);
        }
        else if(vec[b] < vec[c]){//vec[b]<= vec[a] && vec[c]<= vec[a]
            SwapPos(vec, result , c);
        }
        else{
            //vec[c] < vec[b] <= vec[a]
            SwapPos(vec, result, b);
        }
    }
};