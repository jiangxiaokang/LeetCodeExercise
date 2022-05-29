#pragma once
//归并排序
#include "SortCommon.h"

class MergeSort : public SortBase{
protected:
    virtual void Sort(std::vector<int>& vec){
        Process(vec,0,vec.size() - 1);
    }
    void Process(std::vector<int>& vec, int l ,int r){
        if(l== r){
            return;
        }
        int m = l + ((r-l)>>1);
        Process(vec,l, m);
        Process(vec,m+1,r);
        Merge(vec,l,m,r);
    }
    void Merge(std::vector<int>& vec, int l , int m ,int r){
        std::vector<int> tmp;
        int p1 = l;
        int p2 = m+1;
        while(p1 <= m & p2 <= r){
            tmp.push_back(vec[p1] <= vec[p2] ? vec[p1++] : vec[p2++]);
        }
        while(p1<=m){
            tmp.push_back(vec[p1++]);
        }
        while(p2 <= r){
            tmp.push_back(vec[p2++]);
        }
        for(int i =0 ; i<tmp.size();++i){
            vec[i + l] = tmp[i]; 
        }
    }
    virtual void PrintSortName(){
        std::cout<< " Merge Sort" <<std::endl;
    }
};