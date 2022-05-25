#pragma once 

#include <vector>
#include <iostream>


inline void PrintVec(const std::vector<int>& vec){
    for(auto& num : vec){
        std::cout<<num<<",";
    }
    std::cout<<std::endl; 
}

inline void SwapPos(std::vector<int>& vec, int i,int j){
    vec[i] = vec[i]^vec[j];
    vec[j] = vec[i]^vec[j];
    vec[i] = vec[i]^vec[j];
}

class SortBase{
public:
    SortBase() = default;
    virtual ~SortBase() = default;
    void DoSort(std::vector<int>& vec){
        std::cout<<"begin sort"<<std::endl;
        PrintVec(vec);
        Sort(vec);
        std::cout<<"end sort"<<std::endl;
        PrintVec(vec);
    }
protected:
    virtual void Sort(std::vector<int>& vec) = 0;
};