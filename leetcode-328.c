#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {

    int val;
    struct node *next;
} Node;

Node *current, *previous, *first;

void PrintList(Node* first);
void FreeList(Node* first);
Node* oddEvenList(Node* head);

int main(){

    // Create a 6-nodes linked list
    int i;
    for( i=0; i<6; i++) {
        Node *current = (Node*)malloc(sizeof(Node));
        if (i==0){
            current->val = 1;
            first = current;
            previous = current;
        }
        else if (i==1){
            current->val = 2;
            previous->next = current;
            current->next =NULL;
            previous = current;
        }
        else if (i==2){
            current->val = 3;
            previous->next = current;
            current->next =NULL;
            previous = current;
        }
        else if (i==3){
            current->val = 4;
            previous->next = current;
            current->next =NULL;
            previous = current;
        }
        else if (i==4){
            current->val = 5;
            previous->next = current;
            current->next =NULL;
            previous = current;
        }
        else{
            current->val = 6;
            previous->next = current;
            current->next =NULL;
            previous = current;
        }
    }

    PrintList(first);
    
    
    first = oddEvenList(first);
    PrintList(first);
    FreeList(first);
    return 0;
}

void PrintList(Node* first){
    // Decalre the address of input node
    Node *node = first;
    if (first == NULL){
        printf("List is empty!\n");
    }
    else{
        while( node != NULL){
            printf("%d -> ", node->val);
            node = node->next;
        }
        printf ("Null \n");
    }
}

void FreeList(Node* first){
    Node *current, *temp_node;
    current = first;
    while ( current != NULL ){
        // Put the node that wants to be removed into temp_node
        temp_node = current;
        // Let the current node point to the next node
        current = current->next;
        // Free the node
        free(temp_node);   
    }
}

Node* oddEvenList(Node* head){
    int counter=0;
    int oddCounter =0;
    int evenCounter =0;
    Node *ptr = head;

    // empty list case
     if (head == NULL || head->next == NULL) return head;
    
    // traverse through the list, derive the length of the list
    while(ptr != NULL){
        counter++;
        if (counter % 2 == 0){
            evenCounter++;
        }
        else {
            oddCounter++;
        }
        ptr = ptr->next;
    }


    // Create odd list
    Node *oddPtr =  head;
    Node *newOddHead = NULL;
    Node *OddTail = NULL;
    Node *oddPrevious = NULL;
    for (int i=0; i<oddCounter; i++){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->val = oddPtr->val;
        if(i==0){             
            newOddHead = newNode;
        }
        else{
            oddPrevious->next = newNode;
        }
        oddPrevious = newNode;
        if (oddPtr->next != NULL && oddPtr->next->next != NULL) {
            oddPtr = oddPtr->next->next;
        } else {
            break;
        }
    }
    OddTail = oddPrevious;
     if (OddTail != NULL) {
        OddTail->next = NULL;
    }



    // Create even list
    Node *evenPtr =  head->next;
    Node *newEvenHead = NULL;
    Node *evenPrevious = NULL;
    for (int i=0; i<evenCounter; i++){
        Node * newNode = (Node*)malloc(sizeof(Node));
        newNode->val = evenPtr->val;
        if(i==0){
            newEvenHead = newNode;
        }
        else{
            evenPrevious -> next = newNode;
        }
        evenPrevious = newNode;
         if (evenPtr->next != NULL && evenPtr->next->next != NULL) {
            evenPtr = evenPtr->next->next;
        } else {
            break;
        }
    }
     if (evenPrevious != NULL) {
        evenPrevious->next = NULL;
    }

    // Merge two lists
    if (OddTail != NULL) {
        OddTail->next = newEvenHead;
    } else {
        newOddHead = newEvenHead;
    }

    return newOddHead;
}