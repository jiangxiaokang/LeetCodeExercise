#pragma once
#include "TreeInfoDefine.h"
#include <unordered_map>
#include <unordered_set>

class LowestCommonAncestor{
public:

    TreeNode* lca(TreeNode* head, TreeNode* o1, TreeNode* o2){
        std::unordered_map<TreeNode* , TreeNode* > fatherMap;
        fatherMap.insert({head,head});
        process(head, fatherMap);
        std::unordered_set<TreeNode* > father1;
        TreeNode* cur = o1;
        father1.insert(o1);
        while(cur != fatherMap[cur]){
            father1.insert(fatherMap[cur]);
            cur = fatherMap[cur];
        }
        cur = o2;
        while(cur != fatherMap[cur]){
            auto itr = father1.find(cur);
            if(itr!= father1.end()){
                return cur;
            }
            cur = fatherMap[cur];
        }
        return head;
    }

    void process(TreeNode* node, std::unordered_map<TreeNode* , TreeNode*>& fatherMap){
        if(node == nullptr){
            return ;
        }
        fatherMap.insert({node->left, node});
        fatherMap.insert({node->right,node});
        process(node->left, fatherMap);
        process(node->right, fatherMap);
    }

    TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == nullptr || p==node || q == node){
            return node;
        }
        TreeNode* left = lca(node->left, p , q);
        TreeNode* right = lca(node->right, p, q);
        if(left != nullptr && right != nullptr){
            return node;
        }
        return left==nullptr ? right: left;
    }
};