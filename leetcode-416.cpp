#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> memo;

void helper(vector<int>&nums, int index, int currentSum, int target, bool &found){
    if(found) return;
    if(currentSum == target){
        found = true;
        return;
    }
    if(index >=nums.size() || currentSum > target) return;
    
    if(memo[index][currentSum]== 0) return; 
    if(memo[index][currentSum]== 1){
        found =true;
        return;
    }

    helper(nums, index+1, currentSum+nums[index], target, found);
    helper(nums, index+1, currentSum, target, found);
    if(!found) memo[index][currentSum] = 0;
    else memo[index][currentSum] = 1;
}

bool canPartition(vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if(totalSum % 2 !=0) return false;
    bool found=false;
    memo.assign(nums.size() + 1, vector<int>(totalSum/2 + 1, -1));// -1: unreach, 0: false, 1:true
    helper(nums, 0, 0,totalSum/2, found);
    return found;
}

void main(){};