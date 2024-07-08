#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MinStack {
public:
    int val, size = 0;
    MinStack *next;
    MinStack *Top = NULL;

    // 定義建構子
    MinStack() : val(0), next(0) {}
    MinStack(int x) : val(x), next(0) {}
    MinStack(int x, MinStack *nextNode) : val(x), next(nextNode) {}

    void push(int val);
    void pop();
    int top();
    int getMin();
    bool isEmpty();
};

void MinStack::push(int val) {
    if (isEmpty()) {
        Top = new MinStack(val);
        size++;
        return;
    }
    MinStack *newNode = new MinStack(val);
    newNode->next = Top;
    Top = newNode;
    size++;
}

void MinStack::pop() {
    if (isEmpty()) {
        return;
    }
    MinStack *tempNode = Top;
    Top = Top->next;
    delete tempNode;
    size--;
}

int MinStack::top() {
    if (!isEmpty()) {
        return Top->val;
    }
    return -1; // 或任何其他值表示堆疊為空
}

int MinStack::getMin() {
    if (isEmpty()) {
        return -1; // 或任何其他值表示堆疊為空
    }
    MinStack *ptr = Top;
    int minValue = ptr->val;
    while (ptr != NULL) {
        if (ptr->val < minValue) {
            minValue = ptr->val;
        }
        ptr = ptr->next;
    }
    return minValue;
}

bool MinStack::isEmpty() {
    return Top == nullptr;
}

int main() {
    // Input 1
    vector<string> Input1 = {"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"};

    // Input 2 for push
    vector<int> Input2 = {-2, 0, -3};

    // Output 
    vector<int> Output;

    MinStack *obj = new MinStack();

    // iterate over the input array
    for (int i = 1; i < Input1.size(); i++) {
        if (Input1[i] == "push") {
            obj->push(Input2[i - 1]);
            Output.push_back(NULL);
        }
        else if (Input1[i] == "pop") {
            obj->pop();
            Output.push_back(NULL);
        }
        else if (Input1[i] == "getMin") {
            Output.push_back(obj->getMin());
        }
        else if (Input1[i] == "top") {
            Output.push_back(obj->top());
        }
    }

    // Print Output
    for (int i = 0; i < Output.size(); i++) {
        if (Output[i] == NULL) {
            cout << "NULL" << endl;
        } else {
            cout << Output[i] << endl;
        }
    }

    delete obj; // 清理以防止記憶體洩漏
    return 0;
}
