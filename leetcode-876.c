#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

Node *first, *current, *previous;
void PrintList(Node *first);
void FreeList(Node *first);
Node * middleNode(Node *first);

int main(){

    // Create a 3-nodes linked list
    int i;

    for( i=0; i<4; i++) {
        Node *current = (Node*)malloc(sizeof(Node));
        if (i==0){
            current->val = 7;
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
        else{
            current->val = 9;
            previous->next = current;
            current->next =NULL;
            previous = current;
        }
    }

    PrintList(first);
    Node *mid = middleNode(first);
    if (mid != NULL) {
        printf("Middle Node: %d \n", mid->val);
    } else {
        printf("No middle node found.\n");
    }
    FreeList(first);

    return 0;
}

void PrintList(Node* first){
    Node * ptr = first;
    if (ptr == NULL){
        printf("empty list\n");
    }
    else {
        while ( ptr != NULL){
            printf("%d ->", ptr->val);
            ptr = ptr -> next;

        }
    }
    printf("NULL\n");
}

void FreeList(Node* first){
    Node *tmp, *current;
    current = first;
    while(current != NULL){
        tmp = current;
        current = current->next;
        free(tmp);
    }

}

// // Apporach 1
// Node * middleNode(Node *first){
//     Node *current = first;
//     Node *middle= NULL;
//     int counter=0;
//     int middleNodeIndex;
//     bool isEven;


//     // (1) Get the length of list (2) Get the index of the middle
//     while (current != NULL){
//         counter++;
//         if(counter%2 == 0){
//             isEven = true;
//             middleNodeIndex = counter/2;
//         }
//         else{
//             isEven = false;
//             middleNodeIndex = (int)(floor(counter/2));
//         }
//         current = current->next;
        
//     }
    

//     current = first;
//     for (int i=0; i<counter; i++){
//         if ( i == middleNodeIndex){
//             middle = current;
//             break;
//         }
//         current = current->next;
//     }
//     return middle;
// }

// Apporach 2
Node * middleNode(Node *first){
    Node *fast_ptr, *slw_ptr;
    fast_ptr = first;
    slw_ptr = first;

    while (fast_ptr != NULL){
        fast_ptr = fast_ptr->next->next;
        slw_ptr = slw_ptr->next;
    }
    return  slw_ptr;
}