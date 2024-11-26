#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;
bool helper(string s3,string s1, string s2, int i, int j){
    if(i+j == s3.length()){
        return true;
    }
    if(dp[i][j]!= -1) return dp[i][j];

    bool result =false;
    if(i<s3.length() && s1[i] == s3[i+j]){
        result = helper(s3, s1, s2, i+1, j);
    } 
    if(!result && j<s3.length() && s2[j] == s3[i+j]){
        result = helper(s3, s1, s2, i, j+1);
    }
    dp[i][j]=result;
    return result;
}

bool isInterleave(string s1, string s2, string s3){
    if(s3.length()!=s1.length()+s2.length()) return false;
    int n= s1.length();
    int m = s2.length();
    dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
    return helper(s3,s1,s2,0,0);
}

int main(){

    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    if(isInterleave(s1,s2,s3)){
        cout << "Yes, the strings are interleaved." << endl;
    }
    else{
        cout << "No, the strings are not interleaved." << endl;
    }


    return 0;
}