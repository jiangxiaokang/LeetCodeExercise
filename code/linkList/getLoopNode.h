#pragma once

#include "link_list_info.h"

class SolutionLoopNode {
public:
    void test(){
        ListNode l5(5);
        ListNode l4(4,&l5);
        ListNode l3(3,&l4);
        ListNode l2(2,&l3);
        ListNode l1(1,&l2);
        l5.next = &l3;
        ListNode* node = getLoopNode(&l1);
        if(node != nullptr){
            std::cout<<" loop node val = "<<node->val<<std::endl;
        }
        else{
            std::cout<< " no loop node" <<std::endl;
        }
    }

    ListNode *getLoopNode(ListNode *head) {
        if(!head){
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        do{
            if(fast->next && fast->next->next){
                fast = fast->next->next;
                slow = slow->next;
            }
            else{
                return nullptr;//到末尾了
            }
        }while(slow != fast);

        fast = head;
        while(fast!= slow){
            fast=fast->next;
            slow = slow->next;
        }
        return fast;
    }
};