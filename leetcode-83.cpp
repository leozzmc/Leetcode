#include <iostream>
#include <list>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} Node;

Node *first, *current;

void PrintList(Node *first);

Node * deleteDuplicates(ListNode* head);

int main (){
    // Define a 4-nodes linked list
    ListNode node4(3);
    ListNode node3(3, &node4);
    ListNode node2(2, &node3);
    ListNode node1(1, &node2);

    // Print the list
    PrintList(&node1);

    deleteDuplicates(&node1);
    PrintList(&node1);


    return 0;
}

void PrintList(Node *first){
    Node * current = first;
    if(current!= NULL){
        while ( current != NULL){
            cout << current->val << "->" ;
            current = current->next;
        }
    }   
    else{
        cout << "Emppty List" << endl;
    }
    cout << "NULL" << endl;
}

Node * deleteDuplicates(ListNode* head){
    Node * ansHead = head;
    Node * current = head;
    Node *previous  =NULL;

    while (current != NULL){
        if(current == head){ // head
            previous = current;
            current = current->next;
        }
        else{ // the following nodes
            while ( previous->val == current->val && current->next != NULL ){
                ListNode tempNode(0, current->next);
                //tempNode->next = current->next;
                current = current->next;
                previous -> next = current;
            }
            if ( previous->val == current->val && current->next == NULL){
                ListNode tempNode(0, current->next);
                current = current->next;
                previous -> next = current;
            }
            else{
                current = current-> next;
                previous = previous->next;
            } 
        }
    }
    return ansHead;
    
}