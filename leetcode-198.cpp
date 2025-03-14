# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;


int rob(vector<int>& nums){
    if(nums.empty()) return 0;
    else if(nums.size()==1) return nums[0];
    else if(nums.size()==2) return max(nums[0], nums[1]);
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for(int i=2; i<nums.size(); i++){
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[nums.size()-1];
}
int main(){

    vector<int> nums= {2,1,1,2};
    cout << rob(nums) << endl;

    return 0;
}