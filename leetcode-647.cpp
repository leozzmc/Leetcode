#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
bool checkPalindrome(string s, int left, int right){
    if(dp[left][right] != -1) return dp[left][right];

    while(left < right){
        if(s[left] != s[right]){
            dp[left][right] =0;
            return false;
        }
        left++
        right--;
    }
    dp[left][right] = 1;
    return true;
}   

void subStringHelper(string s, int start){
    int n = s.length();
    int count=0;
    dp = vector<vector<int>>(n, vector<int>(n, -1));


    for(int i=start; i<n; i++){
        if(checkPalindrome(s, start, i)){
            count++;
            count += subStringHelper(s, i+1);
        }
        
    }
    return count;
}

int countSubstrings(string s){
    subStringHelper(s, "", 0);
    return count;
}


int main(){
    string s="abc";
    cout << countSubstrings(s) << endl;
    return 0;
}