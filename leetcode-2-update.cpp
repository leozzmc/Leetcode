# include <iostream>
# include <vector>
# include <math.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 struct ListNode *current;

void PrintList(ListNode *first){
    struct ListNode *ptr = first;
    if(first != NULL){
        while(ptr != NULL){
            cout << ptr->val << "->";
            ptr = ptr -> next;
        }
    }
    else{
        cout << "empty list" << endl;
    }
    cout << "NULL" << endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum =0;
    int carry=0;
    ListNode *newHead = new ListNode(0);
    ListNode *current = newHead;


    while( l1 != nullptr || l2 != nullptr ){
        sum = carry;
        if (l1 != nullptr){
            sum += l1->val;
            l1 = l1 -> next;
        }
        if (l2 != nullptr){
            sum += l2->val;
            l2 = l2->next;
        } 
        carry = sum /10;
        current->next = new ListNode(sum % 10);
        current = current -> next;

        
    }
    if(carry > 0){
            current->next = new ListNode(carry);
            current = current -> next;
    }
    return newHead->next;

}

int main(){
    //Create list 1
    // ListNode node1_3(9);
    ListNode node1_2(9);
    ListNode node1_1(9, &node1_2);
    //Print List1
    cout << "list1:";
    PrintList(&node1_1);
    //Create list 2
    //ListNode node2_2(9);
    ListNode node2_1(9);
    //Print List2
    cout << "list2:";
    PrintList(&node2_1);

    //Output
    cout << "Reverse output:";
    PrintList(addTwoNumbers(&node1_1, &node2_1));


    return 0;
}



