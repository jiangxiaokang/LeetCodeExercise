#pragma once

#include "TreeInfoDefine.h"
#include <algorithm>

class SolutionIsBalancedTree{
public:
    bool isBalancedTree(TreeNode* head)
    {
        int height = 0;
        return process(head, height);
    }

    bool process(TreeNode* node, int& height)
    {
        if(node == nullptr){
            height = 0;
            return true;
        }
        int left_height = 0;
        int right_height = 0;
        if(!process(node->left,left_height)){
            return false;
        }
        if(!process(node->right,right_height)){
            return false;
        }
        int dif = std::abs(left_height - right_height);
        if(dif > 1){
            return false;
        }
        height = std::max(left_height,right_height) +1;
        return true;
    }
};