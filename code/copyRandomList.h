#pragma once 
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class SolutionOffer35 {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        Node* cur  = head;
        //add copy
        while(cur){
            Node* next = cur->next;
            Node* copyNode = new Node(cur->val);
            cur->next = copyNode;
            copyNode->next = next;
            cur = next;
        }
        //set random node
        cur = head;
        while(cur){
            Node* copyNode = cur->next;
            if(cur->random){
                copyNode->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        //split and reset
        cur = head;
        Node* ret = cur->next;
        Node* copyNode = ret;
        while(cur){
            copyNode = cur->next;
            Node* tmp =  cur->next->next;
            cur->next = tmp;
            if(!tmp){
                break;
            }
            copyNode->next = tmp->next;
            cur = tmp;
        }
        return ret;
    }
};