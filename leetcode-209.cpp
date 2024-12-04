#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums){
    int left=0, right=0;
    int sum = 0;
    int length = INT_MAX;
    while(right < nums.size()){

        sum += nums[right];
        while( sum >= target){
            length = min(length,right - left+1);
            sum -= nums[left];
            left++;
        }
        right++;
    }

    if(length==INT_MAX) return 0;
    else return length;
}

int main(){
    int target = 7;
    vector<int> nums={2,3,1,2,4,3};
    cout << minSubArrayLen(target, nums) << endl;

    return 0;
}