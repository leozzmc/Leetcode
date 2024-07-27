#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int size = q1.size();
        int result;
        if(q1.empty()){
            cout << "empty queue" << endl;
            return -1;
        }
        for (int i = 0; i < size; i++) {
            //the last element in the queue
            if(i==size-1) {
                result = q1.front();
                q1.pop();
                //copy q2 to q1
                size = q2.size();
                for(int j = 0; j < size; j++) {
                    q1.push(q2.front());
                    q2.pop();
                }
                size =0;
            }
            else{
                q2.push(q1.front());
                q1.pop();
            }
        }
        return result;
    }
    
  
    
    int top() {
        if(!q1.empty()) return q1.back();
        else{
            cout << "empty queue" << endl;
            return -1;
        }
    }
    
    bool empty() {
        if(q1.size()==0) return true;
        else return false;
    }
};

int main(){

    MyStack sk;
    sk.push(1);
    cout << "Stack push: 1" << endl;
    sk.push(2);
    cout << "Stack push: 2" << endl;
    sk.push(3);
    cout << "Stack push: 3" << endl;
    cout << "Pop the top element, which is: " <<  sk.pop() << endl;
    // sk.push(4);
    // cout << "Stack push: 4" << endl;
    // cout << "Pop the top element, which is:" <<  sk.pop() << endl;
    cout << "Pop the top element, which is:" <<  sk.pop() << endl;
    cout << "Pop the top element, which is:" <<  sk.pop() << endl;
    cout << "Is the stack empty? " << sk.empty() << endl;
    cout << "Check the top element:" << sk.top() << endl;
    

    return 0 ;
}