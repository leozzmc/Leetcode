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

int main (){
    // Define a 3-nodes linked list
    ListNode node3(3);
    ListNode node2(2, &node3);
    ListNode node1(1, &node2);

    // Print the list
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