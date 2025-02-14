#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isSubsequence(string s, string t){
    int left=0;
    for(int i=0; i<t.length(); i++){
        if(t[i]==s[left]){
            left++;
        
        }
        if(left == s.length()){
            return true;
        }
        
    }
    return false;
}

int main(){
    string s="axc", t="ahbgdc";
    if(isSubsequence(s,t)){
        cout << "Yes, s is a subsequence of t." << endl;
    }
    else{
        cout << "No, s is not a subsequence of t." << endl;
    }
    return 0;
}