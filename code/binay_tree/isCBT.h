#pragma once
#include <queue>
#include "TreeInfoDefine.h"
/* complete binary tree*/
class Sulotion {
public:
    bool isCBT(NodeTree* head)
    {
        bool leaf = false;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        std::queue<NodeTree*> myQueue;
        myQueue.push(head);
        while(myQueue.empty()){
            head = myQueue.front();
            myQueue.pop();
            left = head->left;
            right = head->right;

            if( (leaf && (left!=nullptr || right!= nullptr)) || (left==nullptr && right!=nullptr)){
                return false;
            }
            if(left){
                myQueue.push(left);
            }
            if(right){
                myQueue.push(right);
            }
            if(left == nullptr || right == nullptr){
                leaf = true;
            }
        }
        return true;
    }
}