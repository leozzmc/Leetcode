#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int helper(vector<int>& nums, int index, int productMax, int productMin , int &answer ){
        if(index == nums.size()) return answer;


        if(nums[index] == 0){
            // check positive product or negitive product
            answer=max(answer, 0);
            return helper(nums, index+1, 1,1,answer);
        }
        
        int nextMax = max( nums[index], max( nums[index]*productMax, nums[index]*productMin));
        int nextMin = min(nums[index], min(nums[index]*productMax, nums[index]*productMin));

        answer = max(answer, nextMax);
        
        return helper(nums, index+1, nextMax, nextMin, answer);
    }

    int maxProduct(vector<int>& nums){
            int ans = INT_MIN;
            int productResult = helper(nums, 0, 1,1, ans);
            return productResult;
    }

void main(){



}