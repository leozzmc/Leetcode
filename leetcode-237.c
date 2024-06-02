#include <stdio.h>
#include <stdlib.h>

// Define struct
typedef struct node {
    int data;
    struct node *next;
} Node;

// Declare nodes
Node *first, *current, *previous;

//Declare functions
void deleteNode(Node* node);
void PrintList(Node* first);
void FreeList(Node* first);


int main(){

    // Create a 3-nodes linked list
    int i;
    for( i=0; i<3; i++) {
        Node * current = (Node*)malloc(sizeof(Node));
        if (i==0){
            current->data = 123;
            first = current;
            previous = current;
        }
        else if (i==1){
            current->data = 456;
            previous->next = current;
            current->next =NULL;
            previous = current;
        }
        else{
            current->data = 789;
            previous->next = current;
            current->next =NULL;
            previous = current;
        }
    }
    // Print original list
    PrintList(first);

    // Test delete node
    deleteNode( first->next );
    //Check if deleted
    PrintList(first);

    FreeList(first);

    return 0;
}


void deleteNode(Node* node){
    node->data = node->next->data;
    node->next = node->next->next;
}

// input parameter is node struct
void PrintList(Node* first){
    // Decalre the address of input node
    Node *node = first;
    if (first == NULL){
        printf("List is empty!\n");
    }
    else{
        while( node != NULL){
            printf("%d -> ", node->data);
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