#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;



nt helper(vector<int>& nums, vector<vector<int>>& memo ,int target, int index , int count, int offset){
    if(index == nums.size()){
        if(count == target) return 1;
        else return 0;
    }
    int key = count + offset;
    if (memo[index][key] != INT_MIN) return memo[index][key];
    int ways = 0;
    ways+= helper(nums,memo, target, index+1, count+nums[index], offset);
    ways+=helper(nums,memo, target, index+1, count-nums[index], offset);
    return memo[index][key] = ways;
}

int findTargetSumWays(vector<int>& nums, int target){
    int totalSum=0;
    for(int n:nums){
        totalSum+=n;
    }
    vector<vector<int>> dp(nums.size(), vector<int>(2*totalSum+1, INT_MIN));
    return helper(nums,dp, target, 0, 0, totalSum);
}

void main(){};