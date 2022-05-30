#pragma once
#include "linkList/link_list_info.h"
#include <stack>
#include <iostream>

class SolutionIsPalindrome {
public:
    void test(){
        ListNode l5(1);
        ListNode l4(2,&l5);
        ListNode l3(3,&l4);
        ListNode l2(2,&l3);
        ListNode l1(1,&l2);
        std::cout<< std::boolalpha <<isPalindrome1(&l1)<<std::endl;
        PrintList(&l1);
    }
    bool isPalindrome(ListNode* head){
        if(head == nullptr){
            return true;
        }
        std::stack<int> stack;
        //第一步
        ListNode* slow = head;
        ListNode* fast = head;
        fast = head;
        if(!fast->next){
            return true;
        }
        fast = fast->next;
        while(fast){
            if(fast->next){
                fast = fast->next->next;
                slow = slow->next;
            }
            else{
                break;
            }
        }
        //push
        slow = slow->next;
        while(slow){
            stack.push(slow->val);
            slow = slow->next;
        }
        //check
        slow = head;
        while(!stack.empty()){
            int val = stack.top();
            if(slow->val != val){
                return false;
            }
            slow = slow->next;
            stack.pop();
        }
        return true;
    } 

    bool isPalindrome1(ListNode* head){
        if(head == nullptr){
            return false;
        }
        ListNode* firstHalfEnd = findFirstHalfEnd(head);
        ListNode* secondHalfReverseStart = reverseList(firstHalfEnd->next); 

        ListNode* p1 = head;
        ListNode* p2 = secondHalfReverseStart;
        bool ret = true;
        while( ret && p2){
            if(p1->val != p2->val){
                ret = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        //恢复后半段链表
        reverseList(secondHalfReverseStart);
        return ret;
    }
    ListNode* findFirstHalfEnd(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next; 
        }
        return prev;
    }
};