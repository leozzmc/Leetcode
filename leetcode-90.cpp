#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;

void subsetHelper(vector<int>& nums, vector<int>& cur, int depth) {
    // Base case: if depth equals the size of nums, add current subset to result
    result.push_back(cur);
    
    for (int i = depth; i < nums.size(); i++) {
        // Skip duplicates
        if (i > depth && nums[i] == nums[i - 1]) continue;
        
        cur.push_back(nums[i]);  // Pick current element
        subsetHelper(nums, cur, i + 1);  // Recurse for next elements
        cur.pop_back();  // Backtrack by removing last added element
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // Sort the input to handle duplicates
    vector<int> cur;
    subsetHelper(nums, cur, 0);
    return result;
}

int main(){
    vector<vector<int>> finalSets;
    vector<int> nums = {4,4,4,1,4};
    finalSets = subsetsWithDup(nums);
    cout << "[";
    for(int i=0; i<finalSets.size();i++){
        cout << "[";
        for(int j=0; j< finalSets[i].size();j++){
            cout << finalSets[i][j] << " ";
        }
        cout << "]," << endl; 
    }
    cout << "]";

    return 0;
}