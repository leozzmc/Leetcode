# include <iostream>
using namespace std;

class StackList;

// Define node structure
class StackNode{
    private:
        int data;
        StackNode *next;
    public:
        //Define constructor
        StackNode(): data(0),next(0){
            //next = 0;
        }
        //Define constructor with initial data
        StackNode(int x):data(x), next(0){}
        //Define constructor with initial data and next node address
        StackNode(int x, StackNode *nextNode):data(x), next(nextNode){};
        friend class StackList;
};

// Define first node, and stack-related functions
class StackList{
    private:
        StackNode *top;
        int size;
    public:
        StackList():top(0),size(0){};
        void Push(int x);
        void Pop();
        bool isEmpty();
        int Top();
        int getSize();
};

void StackList::Push(int x){
    if(isEmpty()){
        top = new StackNode(x);
        size++;
        return;
    }
    //push_front() in linked list
    StackNode *newNode = new StackNode(x);
    //Link the new node to the origin top node
    newNode->next = top;
    //update top pointer
    top = newNode;
    size++;
}

void StackList::Pop(){
    if(isEmpty()){
        cout << "Empty stack, nothing to pop out!" << endl;
        return;
    }
    StackNode *tempNode = top;
    top = top->next;
    delete tempNode;
    // set tempNode to a null pointer, to prevent dangling pointer
    // The constructor will set the *next to  0 (NULL)
    tempNode =0;
    size--;
}

bool StackList::isEmpty(){
    if( size == 0) return true;
    else return false;
}

int StackList::Top(){
    if(isEmpty()){
        cout << "Empty stack, nothing to return" << endl;
        return -1;
    } 
    return top->data;
}

int StackList::getSize(){
    return size;
}

int main(){

    StackList sk;
    sk.Pop();
    sk.Push(32);
    sk.Push(4);
    std::cout << "\ntop: " << sk.Top() << "\nsize: " << sk.getSize() << std::endl;        
    sk.Push(15);
    std::cout << "\ntop: " << sk.Top() << "\nsize: " << sk.getSize() << std::endl;         
    sk.Pop();
    sk.Pop();
    std::cout << "\ntop: " << sk.Top() << "\nsize: " << sk.getSize() << std::endl;          
    sk.Pop();
    std::cout << "\ntop: " << sk.Top() << "\nsize: " << sk.getSize() << std::endl;



    return 0;
}