#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums){
    int left=0, right=0;
    int globalMax = 0;
    int count = 0;

    while(right < nums.size()){

        if(nums[right] == 0){
            count++;
        }

        while(count == 2){
            globalMax =  max(globalMax, right - left);
            if(nums[left] == 0) count--;
            left++;
        }
        right++;
    }
    if(count < 2) globalMax = max(globalMax, right - left);
    return globalMax;
}

int main(){
    vector<int> nums={1,0,1,1,0};
    cout << findMaxConsecutiveOnes(nums) << endl;

    return 0;
}