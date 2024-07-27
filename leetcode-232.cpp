# include <iostream>
# include <stack>

using namespace std;

class MyQueue{
public:
    stack<int> sk1;
    stack<int> sk2;
    int size_Sk1=0;
    int size_Sk2=0;
    void push(int x) {
        sk1.push(x);
        size_Sk1++;
    }
        
    int pop() {
        if(sk1.empty()){
            cout << "Empty queue, nothing to pop" << endl;
            return -1;
        }
        int result;
        for(int i = 0; i < size_Sk1; i++){
            // if it is the last element
            if(i==size_Sk1-1){
                result = sk1.top();
                sk1.pop();
            }
            else{
                sk2.push(sk1.top());
                sk1.pop();
                size_Sk2++;
            }
        }

        //copy sk2 to sk1
        for(int i = 0; i < size_Sk2; i++){
            sk1.push(sk2.top());
            sk2.pop();
        }
        size_Sk2=0;
        size_Sk1--;
        return result;
    }
        
    // queue.front()
    // This is equal to the bottom of the stack
    int peek() {
        if(sk1.empty()){
            cout << "Empty queue, noting to peek" << endl;
            return -1;
        }
        int result;
        for(int i = 0; i < size_Sk1; i++){
            // if it is the last element
            if(i==size_Sk1-1){
                result = sk1.top();
            }
            else{
                sk2.push(sk1.top());
                sk1.pop();
                size_Sk2++;
            }
        }
        //copy sk2 to sk1
        for(int i = 0; i < size_Sk2; i++){
            sk1.push(sk2.top());
            sk2.pop();
        }
        size_Sk2=0;
        return result;
    }
        
    bool empty() {
        if(sk1.empty()) return true;
        else return false;
    }
};

// 12:10 Started to code
// 12:22 Local testing


int main(){

    MyQueue q;
    q.push(1);
    cout << "Push 1 into the queue." << endl;
    q.push(2);
    cout << "Push 2 into the queue." << endl;
    q.push(3);
    cout << "Push 3 into the queue." << endl;
    //should be 1
    cout << "Pop the front element of the queue." << q.pop() << endl;
    q.push(4);
    cout << "Push 4 into the queue." << endl;
    cout << "Checking the front element of the queue." << q.peek() << endl;


    return 0;
}