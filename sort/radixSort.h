#pragma once 

#include "SortCommon.h"

class RadixSort : public SortBase
{
protected:
    virtual void Sort(std::vector<int>& vec){
        int bits = maxBits(vec);
        const static int radix = 10;
        //辅助空间
        std::vector<int> bucket(vec.size(),0);
        //循环次数，最大位数
        for(int i = 0; i < bits ; ++i){
            std::vector<int> count_vec(radix, 0);//词频统计数组
            for(auto& num : vec){
                int j = GetDigit(num,i);
                count_vec[j]++;
            }
            int j = 0;
            for(j = 1; j< radix; ++j){
                count_vec[j] = count_vec[j] + count_vec[j-1];
            }
            for(j = vec.size() -1; j>= 0; --j){
                int d = GetDigit(vec[j],i);
                count_vec[d]--;
                bucket[count_vec[d]] = vec[j];
            }
            vec = bucket;
        }
    }
    virtual void PrintSortName() {
        std::cout<< "radix sort "<<std::endl;
    }

    int maxBits(const std::vector<int>& vec){
        if(vec.empty()){
            return 0;
        }
        int maxNum = vec[0];
        for(int i  = 1;i<vec.size();++i)
        {
            if(vec[i] > maxNum){
                maxNum = vec[i];
            }
        }
        int count = 0;
        while(maxNum >0){
            count++;
            maxNum /=10;
        }
        return count;
    }

    int GetDigit(int num, int count){
        int ret = 0;
        while(count >= 0){
            if(num <= 0){
                return 0;
            }
            ret = num % 10;
            num /= 10; 
            count--;
        }
        return ret;
    }
};