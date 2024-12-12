#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

        vector<int> leftProfit(n, 0);
        vector<int> rightProfit(n, 0);

        int minPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            minPrice = min(minPrice, prices[i]);
            leftProfit[i] = max(leftProfit[i-1], prices[i] - minPrice);
        }

        int maxPrice = prices[n-1];
        for (int i = n-2; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            rightProfit[i] = max(rightProfit[i+1], maxPrice - prices[i]);
        }

        int maxProfit = 0;
        for (int i = 0; i < n; ++i) {
            maxProfit = max(maxProfit, leftProfit[i] + rightProfit[i]);
        }

        return maxProfit;
}

int main(){
    vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
    cout << maxProfit(prices) << endl;  // Output: 6

    return 0;
}