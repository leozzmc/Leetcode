# include <iostream>
using namespace std;

class StackArray{
    private:
        int top; //Index of top element of Stack
        int capacity; // Allocated memory
        int *stack;
        void DoubleCapacity();
    public:
        // Define constructor with initial state: top=-1, capacity=1
        StackArray():top(-1),capacity(1) {
            //Init a int array with capacity=1
            stack = new int[capacity];
        }
        void Push(int x);
        void Pop();
        bool isEmpty();
        int  Top();
        int  getSize();  
};

void StackArray::DoubleCapacity() {
    // Double capacity
    capacity = capacity *2;
    // Reallocate memory
    int *new_stack = new int[capacity];

    //copy elements to new stack
    for(int i = 0; i < capacity/2;i++){
        new_stack[i] = stack[i];
    }

    // free memory, this is used to free memory that allocated by new[]
    delete[] stack;  
    // redrect new_stack to stack
    stack = new_stack;

}

void StackArray::Push(int x) {
    if (top == capacity-1){
        DoubleCapacity();
    }
    stack[++top] = x;
}

void StackArray::Pop() {
    if (isEmpty()) {
        cout << "Empty Stack, nothing to pop!" << endl;
        return;
    }
    //update top
    top--;
}

bool StackArray::isEmpty(){
    if(top == -1){
        return true;
    }
    else {
        return false;
    }
}

// Return top element of stack
int StackArray::Top(){
    if(isEmpty()) {
        cout << "Empty Stack, nothing on the top!" << endl;
        return -1;
    }
    return stack[top];
}

int StackArray::getSize(){
    return top+1;
}

int main(){
    StackArray sk;
    sk.Pop();
    sk.Push(14);
    sk.Push(9);
    cout << "\n top: " << sk.Top() << "\nsize: " << sk.getSize() << endl;
    sk.Push(7);
    cout << "\n top: " << sk.Top() << "\nsize: " << sk.getSize() << endl;
    sk.Pop();
    sk.Pop();
    cout << "\n top: " << sk.Top() << "\nsize: " << sk.getSize() << endl;
    sk.Pop();
    cout << "\n top: " << sk.Top() << "\nsize: " << sk.getSize() << endl;

    return 0;
}