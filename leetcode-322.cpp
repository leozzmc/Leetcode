# include <iostream>
# include <vector>
# include <climits>
using namespace std;


vector<int> dp;
int coinchangehelper(vector<int>& coins, int amount){
    if(amount==0) return 0;
    if(amount <0) return INT_MAX;
    
    if(dp[amount]!=-1) return dp[amount];
    
    int minCount = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int result = coinchangehelper(coins, amount-coins[i]);
        if(result != INT_MAX){
            minCount = min(minCount, result+1);
        }
    }
    dp[amount] = minCount;
    return dp[amount];
}
int coinChange(vector<int>& coins, int amount){
    dp.resize(amount+1, -1);
    int result = coinchangehelper(coins, amount);
    if(result==INT_MAX) return -1;
    else return result;
}

int main(){
    vector<int> coin = {186,419,83,408};
    int amount = 6249;
    cout << "output: " << coinChange(coin, amount) << endl; 

    return 0;
}