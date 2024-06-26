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
    int len1=0, len2=0;
    int val1=0, val2=0;
    int sum;
    vector<int> value1, value2;
    ListNode * current = l1;
    ListNode * previous;
    ListNode * head;

    cout << "\n" << "----------------" << endl;
    //Traverse through list1, derive the length of l1
    while(current != NULL){
        len1++;
        current = current->next;
    }
    current = l1;
    //Derive the value of list1
    while (current != NULL){
        value1.push_back(current->val);
        current = current -> next;
    }

    current = l2;
    //Traverse through list2, derive the length of l2
    while(current != NULL){
        len2++;
        current = current ->next;
    }
    current = l2;
    //Derive the value of list2
    while(current != NULL){
        value2.push_back(current->val);
        current = current->next;
    }

    //value1
    int factor = value1.size() -1;
    for (int i=value1.size()-1; i>=0; i--){
        val1 += value1[i] * pow(10,factor);
        factor--;
    }

    cout << "val1: " << val1 << endl;

    //value2
    factor = value2.size() -1;
    for (int i=value2.size()-1; i>=0; i--){
        val2 += value2[i] * pow(10,factor);
        factor--;
    }

    cout << "val1: " << val2 << endl;
    
    //sum
    sum = val1 + val2;
    cout << "\n" << "sum:" << sum << endl;
    
    // head
    if(sum % 10 != 0){ 
        ListNode* newHead = new ListNode(sum % 10);
        sum = sum /10;
        current = newHead;
        previous  = newHead;
        head = newHead;
    }
    else{ // tail with 0
        // 0 tail
        ListNode* newHead = new ListNode(0);
        sum = sum /10;
        current = newHead;
        previous  = newHead;
        head = newHead;
    }
    
    while (sum  != 0){
        ListNode* newNode = new ListNode(sum % 10);
        current = newNode;
        previous -> next = newNode;
        previous = newNode;
        sum = sum /10;
    }

    if (head == nullptr) {
        head = new ListNode(sum);
    }
    return head;
        
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



