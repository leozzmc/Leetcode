#include <iostream>
#include <stack>
using namespace std;



bool isValid(string s){
    stack<char> sk;
    if(s == "") {return false;};
    // iterate over the string
    for(char c: s){
        if(c == '(' || c == '[' || c == '{'){
            sk.push(c);
        }
        else if (c == ')'){
            if(!sk.empty()){
                if ( sk.top()=='('){
                    sk.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else if (c == ']'){
            if(!sk.empty()){
                if ( sk.top()=='['){
                    sk.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else if (c == '}'){
            if(!sk.empty()){
                if ( sk.top()=='{'){
                    sk.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(sk.empty()){
        return true;
    }
    else{
        return false;
    }

}


int main(){
    string str="";
    cout << "Is it valid?: " << isValid(str) << endl;
    return 0;
}