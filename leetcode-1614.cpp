# include <iostream>
# include <stack>
using namespace std;


int maxDepth(string s) {
    stack<char> sk;
    int counter = 0;
    int maxDepth = 0;
    for (char c: s){
        if(c == '('){
            sk.push(c);
            counter++;
            if(counter >= maxDepth) maxDepth = counter; 
        }
        else if(c == ')'){ // valid nested parentheses, so don't need to check if stack empty before pop()
            sk.pop();
            counter--;
        }
    }
    return maxDepth;
}

int main(){
    string s = "8*((1*(5+6))*(8/6))";
    cout << "Max Depth: " << maxDepth(s) << endl;

    return 0;
}