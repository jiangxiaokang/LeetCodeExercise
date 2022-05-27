#pragma once
#include <vector>
using namespace std;
class FindPeakElementTest {
public:
    int findPeakElement(vector<int>& nums) {
        int count = nums.size();
        if(count <= 1){
            return 0;
        }
        //0位置
        if(nums[0] > nums[1]){
            return 0;
        }
        //n-1 位置
        if(nums[count-1] > nums[count - 2]){
            return count -1;
        }
        return binarySearch1(nums, 0 ,count-1);
    }
    int binarySearch(vector<int>& nums,int left, int right){
        if(left > right){
            return -1;
        }
        int count = nums.size();
        int m = (left + right)/2;
        if( (m-1 < 0 || nums[m-1] < nums[m]) && 
        (m+1 > count-1 || nums[m]> nums[m+1])){
            return m;
        }
        int ret = binarySearch(nums,left,m-1);
        if(ret >= 0){
            return ret;
        }
        ret = binarySearch(nums,m+1,right);
        if(ret >= 0){
            return ret;
        }
        return -1;
    }   
    int binarySearch1(vector<int>& nums, int left, int right){
        if(left > right){
            return -1;
        }
        int count = nums.size();
        int m = (left + right)/2;
        if(m-1 >= 0 && nums[m-1]>nums[m]){
            right = m-1;
            return binarySearch1(nums,left,right);
        }
        if(m+1 <= count-1 && nums[m+1] > nums[m]){
            left = m+1;
            return binarySearch1(nums, left, right);
        }
        return m; 
    } 
};