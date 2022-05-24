#pragma once

#include "SortCommon.h"

class SelectSort : public SortBase
{
protected:
    virtual void Sort(std::vector<int>& vec)
    {
        for(int i = 0; i<vec.size() ; i++){
            int minIndex = i;
            for(int j = i + 1 ; j<vec.size() ; j++){//找i～N-1最小的一个
                if(vec[j] < vec[minIndex]){
                    minIndex = j;
                }
            }
            if(minIndex != i){
                int tmp = vec[i];
                vec[i] = vec[minIndex];
                vec[minIndex] = tmp;
            }
        }
    }
};