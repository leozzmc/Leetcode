#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxProfit(vector<int>& prices){
        int n = prices.size();
        if (prices.size() < 2) return 0;
        
        int maxProfit =0;
        for(int i=1; i< n; i++){
        if(prices[i] > prices[i-1]){
            maxProfit += prices[i]-prices[i-1];
        }
        }
        return maxProfit;
}
int main(){
    vector<int> prices = {7,1,5,3,6,4};

    cout << maxProfit(prices) << endl;  // Output: 7

    return 0;
}