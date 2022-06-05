#pragma once
#include "TreeInfoDefine.h"
#include <algorithm>

class SolutionIsFullBinaryTree{
public:
    struct RetInfo{
        int height = 0;
        int nodes = 0;
    };
    bool isFullBinaryTree(TreeNode* head){
        RetInfo info = process(head);
        return (info.nodes == (2<<info.height - 1));
    }

    RetInfo process(TreeNode* node){
        if(node == nullptr){
            return RetInfo();
        }
        RetInfo info;
        RetInfo leftInfo = process(node->left);
        RetInfo rightInfo = process(node->right);
        info.height = std::max(leftInfo.height , rightInfo.height) + 1;
        info.nodes = leftInfo.nodes + rightInfo.nodes +1;
        return info;
    }

};