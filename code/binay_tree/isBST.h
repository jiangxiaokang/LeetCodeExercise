#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include "TreeInfoDefine.h"
// is binary search tree

class SolutionIsBST
{
public:
    bool IsValidBst(TreeNode* head)
    {
        if(head == nullptr){
            return true;
        }
        bool check =  IsValidBst(head->left);
        if(maxNode && maxNode >= head->val){
            return false;
        }
        maxNode = head;
        return IsValidBst(head->right);
    }

    bool IsValidBSTUnRecur(TreeNode* head){
        std::stack<TreeNode*> stack;
        long long inOrder = (long long)INT_MIN - 1;

        while(!stack.empty() || head!=nullptr){
            while(head!=nullptr){
                stack.push(head);
                head = head->left;
            }
            head = stack.top();
            stack.pop();
            if(head->val <= inOrder){
                return false;
            }
            
            inOrder = head->val;
            head = head->right;
        }
        return true;
    }
    TreeNode maxNode = nullptr;
};