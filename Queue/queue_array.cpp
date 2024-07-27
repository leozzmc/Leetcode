#include <iostream>
#include <vector>

using namespace std;

class QueueList{
    private:
        int front, back;
        vector<int> queue;
    public:
        QueueList():front(NULL), back(NULL), queue(NULL){}
        void Push(int x);
        void Pop();
        int getFront();
        int getBack();
        int getSize();
        bool IsEmpty();
};

void QueueList::Push(int x) {
    queue.push_back(x);
    return;
}

void QueueList::Pop(){
    if(queue.empty()){
        cout << "empty queue" << endl;
        return;
    }
    else{
        queue.erase(queue.begin());
        return;
    }
}

int QueueList::getFront(){
    if(queue.empty()){
        cout << "empty queue" << endl;
        return -1;
    }
    else{
        vector<int>::iterator it=queue.begin();
        return *it;
    }
}

int QueueList::getBack(){
    if(queue.empty()){
        cout << "empty queue" << endl;
        return -1;
    }
    else{
        vector<int>::iterator it=queue.end()-1;
        return *it;
    }

}

int QueueList::getSize(){
    return queue.size();
}

bool QueueList::IsEmpty(){
    if(queue.empty()){
        return true;
    }
    else{ return false; }
}


int main(){

    QueueList q;
    q.Push(25);
    cout << "After Pushing 25: " << "front:" << q.getFront() << " back:" <<  q.getBack() << endl;
    q.Push(50);
    cout << "After Pushing 50: " << "front:" << q.getFront() << " back:" <<  q.getBack() << endl;
    q.Push(77);
    cout << "After Pushing 77: " << "front:" << q.getFront() << " back:" <<  q.getBack() << endl;
    q.Pop();
    cout << "After Poping the front element: " << "front:" << q.getFront() << " back:" <<  q.getBack() << endl;
    q.Pop();
    cout << "After Poping the front element: " << "front:" << q.getFront() << " back:" <<  q.getBack() << endl;
    q.Pop();
    cout << "After Poping the front element: " << "front:" << q.getFront() << " back:" <<  q.getBack() << endl;
    q.Pop();
    cout << "After Poping the front element: " << "front:" << q.getFront() << " back:" <<  q.getBack() << endl;

    return 0;  
}