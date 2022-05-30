#pragma once
#include <iostream>
#include "linkList/link_list_info.h"


class Solution206 {
public:
    void test(){
        ListNode l5(5);
        ListNode l4(4,&l5);
        ListNode l3(3,&l4);
        ListNode l2(2,&l3);
        ListNode l1(1,&l2);
        PrintList(&l1);
        ListNode* head = reverseListRecursive(&l1);
        PrintList(head);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(cur!=nullptr){
            ListNode* next  = cur->next;
            cur->next = prev;
            // if(next == nullptr){
            //     break;
            // }
            prev = cur;
            cur = next;
        } 
        return prev;   
    }
    ListNode* reverseListRecursive(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        //反转head之后的节点
        ListNode* newHead = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;//防止环,第一个节点反转后next为空
        return newHead;
    }
};