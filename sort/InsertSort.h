#pragma once
#include "SortCommon.h"


class InsertSort : public SortBase{
protected:
     virtual void Sort(std::vector<int>& vec){
        for(int i = 1; i<vec.size() ; ++i){//0~i有序
            for(int j = i-1; j>=0 && vec[j]>vec[j+1]; --j){
                SwapPos(vec,j,j+1);
            }
        }
     }
    virtual void PrintSortName(){
        std::cout<< " Insert Sort" <<std::endl;
    }
};