#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head){
    if(head==nullptr) return nullptr; 
    unordered_map <int, int> umap;

    ListNode *ptr = head;

    // Iterate over the list, 
    while( ptr!=nullptr){
        umap[ptr->val]++;
        ptr = ptr->next;
    }

    ListNode *dummy = new ListNode(0, head);
    ListNode *prev = dummy;
    ptr = head;
    while(ptr!=nullptr){
        if(umap[ptr->val]>1){
            prev->next = ptr->next;
        }
        else{
            prev = ptr;
        }
        ptr = ptr->next;
    }

    return dummy->next;
}

void PrintList(ListNode* head){
    ListNode *ptr =head;
    while(ptr!=nullptr){
        cout << ptr->val << " -> ";  
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

int main(){
    ListNode *nodeG = new ListNode(5);
    ListNode *nodeF = new ListNode(4, nodeG);
    ListNode *nodeE = new ListNode(4, nodeF);
    ListNode *nodeD = new ListNode(3, nodeE);
    ListNode *nodeC = new ListNode(3, nodeD);
    ListNode *nodeB = new ListNode(2, nodeC);
    ListNode *nodeA = new ListNode(1, nodeB);

    PrintList(nodeA);
    deleteDuplicates(nodeA);
    PrintList(nodeA);

    return 0;
}