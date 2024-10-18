# include <iostream>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
} Node;


void PrintList(Node *first){
    Node *ptr = first;
    if(first != nullptr){
        while(ptr != nullptr){
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

void reorderList(ListNode* head){
    Node *ptr1 = head;
    Node *ptr2 = head;

    // Find the middle node  of the list
    while( ptr1 != nullptr && ptr2 != nullptr  && ptr2->next !=nullptr){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    // Now the ptr2 point to the end of the list, and the ptr1 point to the middle node
    
    // Reverse the second half of the list
    Node *new_head = ptr1 -> next;
    


}

int main(){

    Node *nodeA = new Node(4, nullptr);
    Node *nodeB = new Node(3, nodeA);
    Node *nodeC = new Node(2, nodeB);
    Node *nodeD = new Node(1, nodeC);

    //Test output
    PrintList(nodeD);


    return 0;
}