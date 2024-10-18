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

ListNode* reverseList(ListNode *head){
    ListNode *prev = NULL;
    ListNode *cur = head;
    while( cur != nullptr){
        ListNode* nextTemp = cur->next;
        cur->next = prev;
        prev =cur;
        cur = nextTemp;
    }
    return prev;
}

void reorderList(ListNode* head){
    if (!head || !head->next) return;
    Node *ptr1 = head;
    Node *ptr2 = head;

    // Find the middle node  of the list
    while( ptr2->next!= nullptr  && ptr2->next->next !=nullptr){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    // Now the ptr2 point to the end of the list, and the ptr1 point to the middle node
    // Reverse the second half of the list

    ptr2 = reverseList(ptr1->next);
    ptr1->next =  nullptr;

    ptr1=head;
    while(ptr2 != nullptr){
        ListNode *nextPtr = ptr1->next;
        ListNode *nextPtr2 = ptr2->next;
        
        ptr1->next =  ptr2;
        ptr1 = nextPtr;
        ptr2->next =  ptr1;
        ptr2 = nextPtr2;

    }

}

int main(){

    Node *nodeD = new Node(4, nullptr);
    Node *nodeC = new Node(3, nodeD);
    Node *nodeB = new Node(2, nodeC);
    Node *nodeA = new Node(1, nodeB);

    //Test output
    PrintList(nodeA);
    reorderList(nodeA);
    PrintList(nodeA);


    return 0;
}