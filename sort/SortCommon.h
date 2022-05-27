#pragma once 

#include <vector>
#include <iostream>
#include <chrono>

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

    using st_clock= std::chrono::steady_clock;
    void DoSort(const std::vector<int>& vec , bool bPrintResult = false){
        std::vector<int> tmp = vec;
        PrintSortName();
        std::cout<<"#### begin sort ####"<<std::endl;
       // PrintVec(tmp);
        st_clock::time_point t1 = st_clock::now();
        Sort(tmp);
        st_clock::time_point t2 = st_clock::now();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        std::cout<<" time laps "<< time_span.count() << " seconds."<< std::endl;
        
        std::cout<<"#### end sort ####"<<std::endl;
        if(bPrintResult){
            PrintVec(tmp);
        }
    }
protected:
    virtual void Sort(std::vector<int>& vec) = 0;
    virtual void PrintSortName() {}
};