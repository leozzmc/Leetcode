#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> parentheseList;
void generateParentheseshelper(int left, int right, vector<string> &parenthese, string current, int n){
    if(current.length() == 2* n ){
        parenthese.push_back(current);
        return;
    }
    
    if(left < n){
        generateParentheseshelper(left+1, right, parenthese, current +"(", n);
    }
    
    if(right < left){
        generateParentheseshelper(left,right+1 ,parenthese,current +")", n);
    }
    
}

vector<string> generateParenthesis(int n){
    string temp="";
    generateParentheseshelper(0,0, parentheseList, temp, n);
    return parentheseList;
}

int main(){
    int n=3;
    vector<string> finalResults;
    finalResults=generateParenthesis(n);

    for(c: finalResults){
        cout << c << endl;
    }
    

    return 0;
}