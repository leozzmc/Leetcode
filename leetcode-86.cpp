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

ListNode* partition(ListNode* head, int x){
    ListNode *dummy = new ListNode();
    ListNode *curr = head;
    dummy->next = head;
    ListNode *prev = dummy;
    ListNode *insertSmall = head;
    ListNode *insertBig = head;

    vector<ListNode*> bigggerNodeList;
    vector<ListNode*> smallerNodeList;

    // while(curr!=nullptr && curr->val < x){
    //     curr = curr->next;
    //     prev = prev->next;
    // }

    //Find the node that larger than x but previous than x
    while(curr->val != x){
        if(curr->val >= x){
            bigggerNodeList.push_back(curr);
            prev = curr;
        }
        if(curr->val < x) insertSmall = curr;
        else  prev = prev->next;

        curr = curr->next;
    }
    // curr = x
    insertBig = curr;

    // Find the node that smaller than x but later than x
    while{curr->val != nullptr}{
        if(curr->val < x){
            smallerNodeList.push_back(curr);
        }
        curr = curr->next;
    }

    // Combine the list
    
    for(auto &node: smallerNodeList){
        insertSmall->next = node;
        insertSmall = node;
    }

    for(auto &node: biggerNodeList){
        insertBig->next = node;
        insertBig = node;
    }

    return dummy->next;
}


void PrintList(ListNode* head){
    ListNode *ptr = head;
    while(ptr != nullptr){
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "->NULL" << endl;
}

int main(){

    ListNode nodeF = ListNode(2);
    ListNode nodeE = ListNode(5, &nodeF);
    ListNode nodeD = ListNode(2, &nodeE);
    ListNode nodeC = ListNode(3, &nodeD);
    ListNode nodeB = ListNode(4, &nodeC);
    ListNode nodeA = ListNode(1, &nodeB);

    PrintList(&nodeA);
    int x = 3;
    partition(&nodeA, x);

    PrintList(&nodeA);


    return 0;
}