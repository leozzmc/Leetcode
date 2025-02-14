#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> finalList;
    sort(nums.begin(), nums.end());
    for(int i=0; i < n-2; i++){
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i+1;
        int right = n-1;
        while(left < right){
            int sum = nums[left] + nums[right] + nums[i];
            if(sum == 0){
                finalList.push_back({nums[i], nums[left], nums[right]});
                while(left < right && nums[left]==nums[left+1]) left++;
                while(left < right && nums[right]==nums[right-1]) right--;
                left++;
                right--;
            }
            else if(sum < 0){
                left++;
            }
            else{
                right--;
            }   
        }
    }
    return finalList;
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> resultList = threeSum(nums);
    for(int i=0; i<resultList.size(); i++){
        for(int j=0; j<3; j++){
            cout << resultList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

