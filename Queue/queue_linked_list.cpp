#include <iostream>
using namespace std;

struct QueueNode {
    int data;
    QueueNode *next;
    QueueNode(): data(0), next(0){};
    QueueNode(int x):data(x), next(0){};
    
};

class QueueList{
    private:
        QueueNode *front;
        QueueNode *back;
        int size;
    public:
        QueueList(): front(0), back(0), size(0){};
        void Push(int x);
        void Pop();
        int getFront();
        int getBack();
        int getSize();
        bool IsEmpty();
};


void QueueList::Push(int x){
    if(IsEmpty()){
        front = new QueueNode(x);
        back = front;
        size++;
        return;  
    }
    QueueNode *newNode = new QueueNode(x);
    back->next = newNode;
    back = newNode;
    size++;
}

void QueueList::Pop(){
    if (IsEmpty()){
        cout << "empty queue" << endl;
        return;
    }
    else{
        QueueNode *tempNode = front;
        front = front->next;
        delete tempNode;
        tempNode = 0;
        size--;
    }
}

int QueueList::getFront(){
    if(IsEmpty()){
        cout << "empty queue" << endl;
        return -1;
    }
    else{
        return front->data;
    }
}

int QueueList::getBack(){
    if(IsEmpty()){
        cout << "empty queue" << endl;
        return -1;
    }
    else{
        return back->data;
    }
}

int QueueList::getSize(){
    return size;
}

bool QueueList::IsEmpty(){
    if(size == 0) return true;
    else return false;
}

int main(){

    QueueList q;
    if(q.IsEmpty()){
        cout << "empty queue" << endl;
    }

    q.Push(24);
    cout<< "After push 24: \n";
    cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(8);
    cout<< "After push 8: \n";
    cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(23);
    cout<< "After push 23: \n";
    cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(13);
    cout<< "After push 13: \n";
    cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    cout<< "After pop the front element: \n";
    cout << "front: " << q.getFront() << "     back: " << q.getBack() << "\n";
    q.Push(35);
    cout<< "After push 35: \n";
    cout << "front: " << q.getFront() << "     back: " << q.getBack() << "\n";
    q.Pop();
    cout<< "After pop the front element: \n";
    cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    cout<< "After pop the front element: \n";
    cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "After pop the front element: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    cout<< "After pop the front element: \n"; 
    q.Pop();


    return 0;
}