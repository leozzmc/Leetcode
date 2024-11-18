#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> dp; 
bool helper(string s, int start, vector<string>& wordDict){
    if(start == s.length()){
        return true;
    }

    if(dp[start]!= -1) return dp[start];

    for(int i=start; i<s.length(); i++){
        string word = s.substr(start, i-start+1);
        if(find(wordDict.begin(), wordDict.end(),word)!=wordDict.end()){
            if(helper(s,i+1, wordDict)){
                return dp[start]=1;
            }
        }
    }
    return dp[start]=0;
}

bool wordBreak(string s, vector<string>& wordDict){
    dp.resize(s.length()+1, -1);
    return helper(s,0 ,wordDict);
}
int main(){
    string s="leetcode";
    vector<string> wordDict = {"leet","code"};
    
    cout << wordBreak(s,wordDict) << endl;

    return 0;
}