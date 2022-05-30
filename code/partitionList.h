#pragma once

#include "linkList/link_list_info.h"

class SolutionPartitionList{
public:
    void test(){
        ListNode l5(1);
        ListNode l4(2,&l5);
        ListNode l3(3,&l4);
        ListNode l2(4,&l3);
        ListNode l1(5,&l2);
        PrintList(&l1);
        ListNode* p = PartitionList(&l1, 3);
        PrintList(p);
    }
    //
    ListNode* PartitionList(ListNode* head,int val){
        ListNode small(0);
        ListNode large(0);
        ListNode* smallEnd = &small;
        ListNode* largeEnd = &large;
        while(head){
            if(head->val < val){
                smallEnd->next = head;
                smallEnd = smallEnd->next;
            }
            else{
                largeEnd->next = head;
                largeEnd = largeEnd->next;
            }
            head = head->next;
        }
        largeEnd->next = nullptr;//处理最后一个数的next
        smallEnd->next = large.next;
        return small.next;
    }
};