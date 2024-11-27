
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
int helper(vector<int>& prices, int start, int canBuy){
    if(start >= prices.size()) return 0;
    
    
    if(dp[start][canBuy]!= -1) return dp[start][canBuy];

    //Not buy
    int cooldown = helper(prices,start+1, canBuy);

    //Buy
    if(canBuy == 1){
        int sum = -prices[start] + helper(prices,start+1,0);
        dp[start][canBuy] = max(cooldown, sum);
    } 
    // Sell
    else if(canBuy == 0){
        int sum = prices[start]+helper(prices,start+2,1);
        dp[start][canBuy] = max(cooldown, sum);
    }
    
    return dp[start][canBuy];
}

int maxProfit(vector<int>& prices){
    if(prices.size()<=1) return 0;
    dp = vector<vector<int>>(prices.size(), vector<int>(2, -1));
    return helper(prices,0, true);
}
int main(){
    vector<int> prices = {1,2,4};
    cout << maxProfit(prices) << endl;

    return 0;
}