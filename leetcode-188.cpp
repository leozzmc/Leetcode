#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if(n<2) return 0;
    
    vector<int> dpBuy(k+1, INT_MIN);
    vector<int> dpSell(k+1,0);

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= k; j++) {
    
            dpBuy[j] = max(dpBuy[j], dpSell[j-1] - prices[i]);
            dpSell[j] = max(dpSell[j], dpBuy[j]+ prices[i]);
        }
    }
    return dpSell[k];
}


int main(){
    vector<int> prices = {2,4,1};
    int k = 2;
    cout << maxProfit(k, prices) << endl;  // Output: 7
    return 0;
}