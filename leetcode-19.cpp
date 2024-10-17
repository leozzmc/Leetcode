#include <iostream>
using namespace std;


typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
} Node;

void PrintNode(Node *head){
    Node *ptr=head;
    while(ptr!=nullptr){
        cout<<ptr->val<< "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

Node* removeNthFromEnd(Node* head, int n){
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return nullptr;
        Node *ptr=head;
        Node *prev=ptr;
        Node *temp = nullptr;
        int count = 1;
        int len=1;
        
        while(ptr!=nullptr && ptr->next!=nullptr){
            ptr = ptr->next;
            len++;
        }
        cout << len << endl;
        ptr=head;
        int m = len-n+1;
        // delete head
        if(m==1){
            head = ptr->next;
            return head;
        }
        //delete body
        while(ptr!=nullptr && count<m){
            prev = ptr;
            ptr = ptr->next;
            count++;
        }
        temp = ptr->next;
        prev->next = temp;
        ptr=nullptr;
        delete ptr;
        return head;
    }


int main(){

    Node *nodeE = new Node(5, nullptr);
    Node *nodeD = new Node(4, nodeE);
    Node *nodeC = new Node(3, nodeD);
    Node *nodeB = new Node(2, nodeC);
    Node *nodeA = new Node(1, nodeB);

    PrintNode(nodeA);
    removeNthFromEnd(nodeA, 3);
    PrintNode(nodeA);
    


    return 0;
}