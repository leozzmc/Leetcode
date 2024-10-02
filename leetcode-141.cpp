#include <iostream>
#include <unordered_map>
using namespace std;

typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(NULL) {};
    ListNode(int x): val(x), next(NULL) {};
    ListNode(int x, ListNode *node): val(0), next(node) {};
} Node;

Node *ptr;

unordered_map<ListNode*, int> umap;

void PrintList(Node *current){
    if(current== NULL){
        cout << "Empty list" << endl;
        return;
    }
    while(current->next != NULL){
        cout << current->val << "->";
    }
    cout << "NULL" << endl;
}

bool hasCycle(Node *head){
    Node *ptr = head;

    while(ptr != NULL){
        if(umap.find(ptr) != umap.end()){
            return true;
        }
        umap[ptr] = ptr->val;
        ptr = ptr->next;
    }
    return false;
}

int main(){

    Node nodeD(-4);
    Node nodeC(0, &nodeD);
    Node nodeB(2, &nodeC);
    Node nodeA(3, &nodeB);
    //nodeD.next = &nodeB;

    // Should be time-limit exceeded, since the cycle exist.
    //PrintList(&nodeA);
    cout << hasCycle(&nodeA);
    

    return 0;
}