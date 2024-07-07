#include <iostream>
#include <string>
#include <stack>
using namespace std;

string simplifyPath(string path){
    string output="";
    stack<string> sk;
    
    for(int i=0; i<path.size();i++){
        if(path[i]=='/'){
            continue;
        }
        string temp="";
        while(i<path.size() && path[i] != '/'){
        temp += path[i];
        ++i;
        }
        if(temp=="."){
            continue;
        }
        else if(temp==".."){
            if(!sk.empty()){
                sk.pop();    
            }
        }
        else{
            sk.push(temp);
        }
    }
    
    while(!sk.empty()){
        output = '/'+sk.top() + output;
        sk.pop();
    }
    
    if(output.size() == 0){
        return "/";
    }
    return output;
}


int main(){
    string inputPath = "/.../a/../b/c/../d/./";
    cout << simplifyPath(inputPath) << endl;
    return 0;
}