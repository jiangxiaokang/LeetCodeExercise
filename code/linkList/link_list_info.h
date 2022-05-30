#pragma once

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

inline static void PrintList(ListNode* head){
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