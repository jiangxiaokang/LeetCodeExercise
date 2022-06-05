#pragma once

#include "link_list_info.h"

class SolutionIntersectionNode {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* loopA = getLoopNode(headA);
        ListNode* loopB = getLoopNode(headB);
        if(!loopA && !loopB){
            return BoothNoLoop(headA,headB);
        }
        else if(loopA && loopB){
            return BothLoop(headA,loopA,headB,loopB);
        }
        else{
            return nullptr;
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

    ListNode* BoothNoLoop(ListNode* headA, ListNode* headB){
            if(headA == nullptr || headB == nullptr){
                return nullptr;
            }
            ListNode* endA = headA;
            ListNode* endB = headB;
            int len = 0;
            while(endA->next){
                endA = endA->next;
                len += 1;
            }
            while(endB->next){
                endB = endB->next;
                len -= 1;
            }
            if(endA != endB){
                return nullptr;
            }
            endA = headA;
            endB = headB;
            if(len>0){
                while(len>0){
                    endA = endA->next;
                    len -= 1;
                }
            }
            else{
                while(len<0){
                    endB = endB->next;
                    len += 1;
                }
            } 
            while(endA!= endB){
                endA= endA->next;
                endB = endB->next;
            }
            return endA;
    }

    ListNode* BothLoop(ListNode* headA,ListNode* loopA,ListNode* headB,ListNode* loopB)
    {
        if(loopA == loopB){
            ListNode* nextA = loopA->next;
            loopA->next = nullptr;
            ListNode* nextB = loopB->next;
            loopB->next = nullptr;
            ListNode* intersectionNode = BoothNoLoop(headA,headB);
            loopA->next = nextA;
            loopB->next = nextB;
            return intersectionNode;
        }
        else{
            ListNode* cur = loopA->next;
            while(cur!=loopA){
                if(cur == loopB){
                    return loopA;
                }
                cur = cur->next;
            }
            return nullptr;
        }
    }
};