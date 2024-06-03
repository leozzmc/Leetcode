#include <stdio.h>
#include <stdlib.h>


typedef struct node {
      int val;
      struct node *next;
} Node;

Node * first, *current, *previous;

Node* deleteNode(Node* first, int item);
void PrintList(Node* first);
void FreeList(Node* first);

int main(){

    // Create a 4-nodes linked list
    int i;
    for( i=0; i<5; i++) {
        Node * current = (Node*)malloc(sizeof(Node));
        if (i==0){
            current->val = 7;
            first = current;
            previous = current;
        }
        else if (i==1){
            current->val = 7;
            previous->next = current;
            current->next =NULL;
            previous = current;
        }
        else if (i==2){
            current->val = 7;
            previous->next = current;
            current->next =NULL;
            previous = current;
        }
        else if (i==3){
            current->val = 7;
            previous->next = current;
            current->next =NULL;
            previous = current;
        }
        else{
            current->val = 7;
            previous->next = current;
            current->next =NULL;
            previous = current;
        }
    }
    PrintList(first);
    deleteNode(first, 7);
    PrintList(first);
    FreeList(first);
    return 0;
}

void PrintList(Node* first){
    Node * ptr = first;
    if (ptr == NULL){
        printf("List is empty!\n");
    }
    else{
        while(ptr != NULL){
            printf("%d -> ", ptr->val);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

Node* deleteNode(Node* first, int item){
    Node * ptr = first;
    Node * previous = NULL;
    // empty list
    if (ptr== NULL){
        printf("empty list\n");
        return ptr;   
    }
    // Handle first node
    // if (ptr->val == item && ptr != NULL ){
    //     Node * tmp = ptr;
    //     first = ptr->next;
    //     ptr = ptr->next;
    //     free(tmp);
    // }
    // else{
    //     while( ptr != NULL){
    //         if ( ptr->val == item){
    //             Node *tmp = ptr;
    //             previous->next = ptr->next;
    //             ptr = ptr->next;
    //             free(tmp);
    //         }
    //         else{
    //             previous = ptr;
    //             ptr = ptr->next;
    //         }
    //       }
    //     }

    while( ptr != NULL){
        if ( ptr->val == item){
            Node *tmp = ptr;
            if( ptr == first ){
                first = ptr->next;
                ptr = ptr->next;
                free(tmp);
            }
            else{   
                previous->next = ptr->next;
                ptr = ptr->next;
                free(tmp);
            }     
        }
        else{
            previous = ptr;
            ptr = ptr->next;
        }
        }
    
    return first;
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