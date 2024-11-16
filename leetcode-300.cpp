#include <iostream>
#include <vector>
using namespace std;


int lengthOfLIS(vector<int>& nums){
    int n = nums.size();
    if(n == 0) return 0;
    int max_length =1;
    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j <i; j++){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        max_length = max(max_length ,dp[i]);
    }
    return max_length;
}


int main(){

    vector<int> nums = {3,2,1};
    cout << lengthOfLIS(nums)  << endl;

    return 0;
}