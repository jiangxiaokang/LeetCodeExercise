#pragma once

#include "SortCommon.h"

class BubbleSort :public SortBase
{
protected:

    virtual void Sort(std::vector<int>& vec){
        for(int endPos = vec.size() - 1; endPos>0;--endPos){
            for(int i = 0; i<endPos ; ++i){//0~endPos-1
                if(vec[i]>vec[i+1]){
                    // int tmp = vec[i];
                    // vec[i] = vec[i+1];
                    // vec[i+1] = tmp;
                    SwapPos(vec,i,i+1);
                }
            }
        }
    } 
    virtual void PrintSortName(){
        std::cout<< " Bubble Sort" <<std::endl;
    }
};

