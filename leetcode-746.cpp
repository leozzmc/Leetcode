# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;


vector<int> dp;
int helper(vector<int>& cost, int n){
    if(dp[n]!= -1) return dp[n];
    if(n <0){
        return 0;
    }
    if(n == 0 || n ==1){
        dp[n] = cost[n];
        return dp[n];
    }
    
    
    dp[n] =  cost[n] + min(helper(cost, n-1), helper(cost, n-2));
    
    return dp[n];
}

int minCostClimbingStairs(vector<int>& cost){
    int n = cost.size();
    dp.resize(n, -1);
    return min(helper(cost, n-1), helper(cost, n-2));
}
int main(){

    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost) << endl;

    return 0;
}

