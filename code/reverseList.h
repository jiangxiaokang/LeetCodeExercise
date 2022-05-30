#pragma once
#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){

    }
    ListNode(int x):val(x),next(nullptr){

    }
    ListNode(int x, ListNode* next):val(x),next(next){

    }
};

static void PrintList(ListNode* head){
    while(head){
        std::cout<<head->val;
        head=head->next;
        if(head){
            std::cout<<"->";
        }
        else{
            std::cout<<std::endl;
        }
    }
}

class Solution206 {
public:
    void test(){
        ListNode l5(5);
        ListNode l4(4,&l5);
        ListNode l3(3,&l4);
        ListNode l2(2,&l3);
        ListNode l1(1,&l2);
        PrintList(&l1);
        ListNode* head = reverseList(&l1);
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
};