#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxProfit(vector<int>& prices){
    if(prices.size() < 2) return 0;
    int n = prices.size();
    int minValue = INT_MAX;
    int maxValue = 0;

    for(int i=0; i<n; i++){
        minValue = min(minValue, prices[i]);
        maxValue = max(maxValue, prices[i] - minValue);
    }
    return maxValue;
}
int main(){

    // vector<int> prices = {7, 1, 5, 3, 6, 4};
    // vector<int> prices = {7, 6,4,3,1};
    vector<int> prices = {1, 200};
    

    cout << maxProfit(prices) << endl;  // Output: 5

    return 0;
}