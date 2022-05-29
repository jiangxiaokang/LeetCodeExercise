#pragma once

#include "SortCommon.h"
//完全二叉树, 大根堆
class HeapSort : public SortBase
{
public:
    virtual void Sort(std::vector<int>& vec) {
        if(vec.size() <= 1){
            return;
        }
        //heap insert O(NlogN)
        // for(int i  = 1; i< vec.size() ; ++i){
        //     HeapInsert(vec, i);
        // }
        //heapify O(N)
        for(int i = vec.size()/2 - 1; i >= 0; --i){
            Heapify(vec, i, vec.size());
        }

        //heapify
        int heapSize = vec.size();
    
        // do{
        //     SwapPos(vec,0,--heapSize);
        //     Heapify(vec,0,heapSize);
        // }while(heapSize > 0);
        SwapPos(vec, 0 , --heapSize);
        while(heapSize > 0 ){
            Heapify(vec, 0 , heapSize);
            SwapPos(vec, 0, --heapSize);
        }
    }

    virtual void PrintSortName() {
        std::cout<<" heap sort " <<std::endl;
    }

protected:
    static void HeapInsert(std::vector<int>& vec, int index){
        while(vec[index] > vec[(index-1)/2]){
            SwapPos(vec,index, (index-1)/2);
            index = (index - 1) / 2;
        }
    }
    static void Heapify(std::vector<int>& vec, int index, int heapSize){
        int left = index * 2  + 1;
        while(left < heapSize){
            int largest = (left+1 < heapSize && vec[left+1]>vec[left])? left + 1 : left;
            if(vec[largest] > vec[index]){
              SwapPos(vec, largest, index);
              index = largest;
              left = index*2 +1;  
            }
            else{
                break;
            } 
        }
    }
};