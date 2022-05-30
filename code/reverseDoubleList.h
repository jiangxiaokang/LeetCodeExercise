#pragma once
#include <iostream>

struct DoubleLinkListNode{
    int val;
    DoubleLinkListNode* prev;
    DoubleLinkListNode* next;
    DoubleLinkListNode(int x):val(x),prev(nullptr),next(nullptr){

    }
};

static void PrintDoubleLinkList(DoubleLinkListNode* head){
    while(head){
        if(head->prev){
            std::cout<< "<-";
        }
        std::cout<< head->val;
        if(head->next){
            std::cout<<"->";
        }

        head = head->next;
    }
    std::cout<<std::endl;
}

class SolutionDoubleLinkList{
public:
    DoubleLinkListNode* reverse(DoubleLinkListNode* head){
        DoubleLinkListNode* prev = nullptr;
        DoubleLinkListNode* curr = head;
        while(curr){
            prev = curr->prev;
            curr->prev = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr->prev;//移动到下一个节点
        }
        return prev;
    }

    DoubleLinkListNode* reverse2(DoubleLinkListNode* head){
        DoubleLinkListNode* prev = nullptr;
        DoubleLinkListNode* curr = head;
        while(curr){
            prev = curr->prev;
            curr->prev = curr->next;
            curr->next = prev;
            //prev = curr;
            curr = curr->prev;//移动到下一个节点
        }
        if(prev){
            return prev->prev;
        }
        //只有一个节点，或者空节点
        return head;
    }   

    void test(){
        DoubleLinkListNode l0(0);
        DoubleLinkListNode l1(1);
        DoubleLinkListNode l2(2);
        l0.next = &l1;
        l1.prev = &l0;
        l1.next = &l2;
        l2.prev = &l1;

        PrintDoubleLinkList(&l0);
        DoubleLinkListNode* head = reverse(&l0);
        PrintDoubleLinkList(head);

        head = reverse2(head);
        PrintDoubleLinkList(head);
    }
};

