# include <iostream>
# include <stack>
# include <vector>
# include <math.h>
# include <string>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> sk;

    for(int i=0; i<tokens.size();i++){
        // if it is operators
        if(tokens[i]== "+" ){
            if(!sk.empty()){
                int arg2 = (int)sk.top();
                sk.pop();
                int arg1 = (int)sk.top();
                sk.pop();
                sk.push(arg1 + arg2);
            }
        }
        else if(tokens[i]== "-"){
            if(!sk.empty()){
                int arg2 = (int)sk.top();
                sk.pop();
                int arg1 = (int)sk.top();
                sk.pop();
                sk.push(arg1 - arg2);            
            }
        }
        else if(tokens[i]== "*" ){
            if(!sk.empty()){
                int arg2 = (int)sk.top();
                sk.pop();
                int arg1 = (int)sk.top();
                sk.pop();
                sk.push(arg1 * arg2);  
                
            }
        }
        else if(tokens[i]== "/"){
            if(!sk.empty()){
                int arg2 = (int)sk.top();
                sk.pop();
                int arg1 = (int)sk.top();
                sk.pop();
                if(arg2 == 0){
                    return -1;
                }
                sk.push(floor(arg1 / arg2));
            }
        }
        else{
            //only push operands
            sk.push(stoi(tokens[i]));
        }
    }
    return sk.top();
}

int main(){

    vector<string> tokens= {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << "output: " << evalRPN(tokens) << endl;
    return 0;
}