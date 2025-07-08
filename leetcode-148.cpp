#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode():val(),next(nullptr) {};
        ListNode(int value, ListNode *nodeVal):val(value),next(nodeVal){};
};

ListNode* findMiddle(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode dummy;
    ListNode *tail = &dummy;

    while(l1 && l2){
        if(l1->val < l2->val){
            tail->next = l1;
            l1 = l1->next;
        }
        else{
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if(l1){
        tail->next= l1;
        l1=l1->next;
    }
    else{
        tail->next = l2;
        l2 = l2->next;
    }
    return dummy->next;
} 



ListNode* sortList(ListNode* head){
    if(!head || !head->next) return head;

    ListNode *mid = findMiddle(head);
    ListNode *right= mid->next;
    mid->next = nullptr;

    ListNode *left_sorted = sortList(head);
    ListNode *right_sorted = sortList(right);

    return merge(left_sorted, right_sorted);
}


int main(){

    ListNode nodeA(3, nullptr);
    ListNode nodeB(1, &nodeA); 
    ListNode nodeC(2, &nodeB); 
    ListNode nodeD(4, &nodeC);
    ListNode *head = &nodeD; 

    //printList
    ListNode *ptr = head;
    while(ptr!=nullptr){
        cout << ptr->val << "->"; 
        ptr = ptr->next;
    }
    cout << "null" << endl;

    return 0;
}