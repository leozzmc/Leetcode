# include <iostream>
# include <unordered_map>
# include <vector>
# include <algorithm>

using namespace std;


int longestConsecutive(vector<int>& nums){
    if(nums.size()==1) return 1;

    int counter = 1;
    int maxValue = 1;
    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size();i++){
        if(nums[i]-nums[i-1] == 0) continue;
        if(nums[i]-nums[i-1] == 1){
            counter++;
        }
        else{
            counter = 1;
        }
        maxValue = max(maxValue, counter);
    }


    return maxValue;
}

int main(){
    // vector<int> nums = {100,4,200,1,3,2};
    vector<int> nums = {1,2,0,1};

    cout << longestConsecutive(nums) << endl;

    return 0;
}