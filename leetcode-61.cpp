#include <iostream>
#include <vector>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *node): val(x), next(node) {};
} node;


node* rotateRight(node* head, int k){
    if(head == nullptr) return nullptr;
    if(!head || !head->next || k==0) return head; 

    //find the last node of the list
    node *last = head;
    int length = 1;
    
    while(last->next!=nullptr){
        last = last->next;
        length++;
    }
    last->next = head;
    
    //Find new head positions
    k = k % length;
    int countToNewHead = length - k;
    node* newTail = head;
    for(int i=1; i<countToNewHead; i++){
        newTail = newTail -> next; 
    }
    
    node *newHead = newTail-> next;
    newTail->next = nullptr;
    return newHead;
}

void PrintList(node* head){
    node *ptr=head;
    while(ptr!=nullptr){
        cout << ptr->val << " -> ";
        ptr=ptr->next;
    }
    cout << "->NULL" << endl;
}

int main(){

    // Define a test linked list
    node node5(5);
    node node4(4, &node5);
    node node3(3, &node4);
    node node2(2, &node3);
    node node1(1, &node2);
    int k=2;

    // Print the original list
    cout << "Original List: ";
    PrintList(&node1);

    //Rotate the list to the right by k positions
    cout << "Rotated List: ";
    node Node();
    PrintList(rotateRight(&node1,k));



    return 0;
}