#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int helper(int n){
    if(dp[n]!=0) return dp[n];
    else if(n==1) return dp[1]=1;
    else if(n==2) return dp[2]=2;
    dp[n]=helper(n-1)+ helper(n-2);
    return dp[n];
}

int climbStairs(int n){
    dp = vector<int>(n+2, 0);
    return helper(n);
}
int main(){
    
    int n=3;
    cout << climbStairs(n);
    return 0;
}