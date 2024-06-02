#include <stdio.h>
#include <stdlib.h>

// define node
typedef struct node
{
    int data;
    struct node *next;
}Node;

Node *first_node;
Node *current_node;
Node *previous_node;

// Declare Fuctions

void create_new_node(int node_nums);
void PrintList(Node* first);
void FreeList(Node* first);
Node* SearchNode(Node* first, int item);
void InsertNode(Node* node, int item);
void push_front(int item);
void push_back(int item);
Node* DeleteNode( Node* first,Node* node);
void Reverse();

int main(){

    int node_numbers;
    int item;
    printf("The numbers of nodes:");
    scanf("%d",&node_numbers);
    create_new_node(node_numbers);
    current_node = first_node;
    while (current_node!= NULL){
        printf("[%p]|",current_node);
        printf("Data: %d",current_node->data);
        printf("| Addr. of next node=%p \n",current_node->next);
        current_node=current_node->next;
    }

    // Traverse the list of nodes
    printf("=========================================================\n\n");
    PrintList(first_node);
    printf("Serach Nodes: ");
    scanf("%d",&item);
    if (SearchNode(first_node,item)){ printf("Node found\n");} else {printf("Node not found\n");}


    printf("Insert Node:");
    // User input data
    scanf("%d",&item);
    if (SearchNode(first_node,item)){ 
        printf("Node exisit in the list");
    } 
    else {
        // Insert behind the current node
        InsertNode(first_node,item);
        PrintList(first_node);
    }

    FreeList(first_node);

    system("pause");
    return 0;
}

void create_new_node(int node_nums){
    int i;
    for (i=0; i< node_nums; i++){
        // Declare new node
        current_node = (Node*)malloc(sizeof(Node));
        printf("Data for node %d : ",i+1);
        // Enter node data
        scanf("%d", &(current_node->data));
        
        // First node, don't have previous node, so let the first_node and previous_node equal to current_node
        if(i==0){
            first_node = current_node;
            previous_node = current_node;
        }
        else{
            // Set the previous node point to the current node
            previous_node->next = current_node;
            current_node->next = NULL;
            // Set the previous node to current node, prepare to next node creation (or not)
            previous_node = current_node;
        }
    }
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

// Return value should be the address of the node
Node* SearchNode(Node* first, int item){
    Node * node = first;
    while ( node != NULL){
       
        if (node->data == item){
            return node;
        }
        else{
            node = node->next;
        }
    }
}

void InsertNode(Node* node, int item){
    Node *new_node;
    new_node = (Node*)malloc(sizeof(Node));
    // Point the new node to the nexy item of original node
    new_node->data = item;
    new_node->next = node->next;
    // Point the original node to new node
    node -> next = new_node;
}

// Insert a node to the front of the list
void push_front(int  item){
    Node * new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = first_node; // new node pointer point to original first node
    first_node = new_node;  // Update the first node to the new node
}

// Insert a node to the back of the list
void push_back(int item){
    Node * new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = NULL;
    // Handle empty list
    if (first_node == NULL){
        first_node = new_node;
    }
    else{
        // Initailize the current node to the first node for traversal
        Node * current_node = first_node;
        while (current_node->next != NULL){
            // traverse through the list
            current_node = current_node->next;
        }
        // Point to the new node
        current_node->next = new_node;
    }
}

Node* DeleteNode(Node* first ,Node* node){
    Node* ptr= first;
    if (first == NULL)
    {
        print("Noting to print\n");
    }
    // Delete first node of the list
    if (node == first){
        // Update the first pointer to the next node
        first = first->next;
        free(node);
        return first;
    }
    else{
        // ptr traverse through the list
        while (ptr->next != node)
        {
            ptr = ptr->next;
        }
        ptr->next = node->next;
        free(node);
        return first;
        
    }
}

void Reverse(){
    
    
    Node * current, previous, preceding;
    previous = NULL;
    current = first_node;
    // preceding node store the previous address of the current node
    preceding = first_node->next;
    
    while (preceding != NULL){
        // pointer the current node to the NULL (previous) node
        current->next = previous;
        // Update previous poinert to current pointer
        previous = current;
        // Update current pointer to the preceding point
        current = preceding;
        // Update the preceding pointer to the next node;
        preceding = preceding->next;
    }
    current->next = previous;
    first_node=current;    
}