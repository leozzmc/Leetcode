#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head){
    if(!head) return nullptr;
    Node *ptr = head;
    
    unordered_map <Node*, Node*> randomMap;

    while(ptr != nullptr){
        randomMap[ptr] = new Node(ptr->val);
        ptr = ptr->next;
    }

    ptr = head;
    while(ptr != nullptr){
        randomMap[ptr]->next = randomMap[ptr->next];
        randomMap[ptr]->random = randomMap[ptr->random];
        ptr = ptr->next;
    }


    return randomMap[head];
}

int main(){

    // Define linked list
    Node* node1 = new Node(7);
    Node* node2 = new Node(13);
    Node* node3 = new Node(11);
    Node* node4 = new Node(10);
    Node* node5 = new Node(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    node1->random = NULL;
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node1;

    // Test
    Node *newHead =  copyRandomList(node1);

    // Print new linked list
    Node* temp = newHead;
    while(temp!=NULL){
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    Node *ptr= newHead;
    cout << "Random Pointers: "; 
    while (ptr != NULL) {
        cout << "[" << ptr->val << "]:random:";
        if (ptr->random) {
            cout << ptr->random->val;
        } else {
            cout << "NULL";
        }
        cout << " ";
        ptr = ptr->next;
    }
    
    
    return 0;
}