#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right){
    
    ListNode *dummyNode = new ListNode(0);
    dummyNode->next = head;
    ListNode *leftNode = dummyNode;

    // Find the left and right node
    for(int i=1; i<left; i++){
        leftNode = leftNode->next;
    }
    
    ListNode *prev=nullptr;
    ListNode *ptr=leftNode->next;
    for(int i=left; i<=right; i++){
        ListNode *temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
        left++;
    }
    

    // Connect the reversed sublist with the original list
    leftNode->next->next = ptr;
    leftNode->next = prev;

    return dummyNode->next;
}

void PrintList(ListNode* head){
    ListNode* ptr = head;
    while(ptr!=nullptr){
        cout<<ptr->val<< "->";
        ptr = ptr->next;
    }
    cout<<"NULL" << endl;
}

int main(){
    ListNode nodeE = ListNode(5);
    ListNode nodeD = ListNode(3,&nodeE);

    PrintList(&nodeD);
    int left = 1, right = 2;

    PrintList(reverseBetween(&nodeD, left, right));

    return 0;
}