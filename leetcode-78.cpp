#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;
void subsetsHelper(vector<int>& nums, vector<int>& current, int depth){
    if(depth == nums.size()){
        result.push_back(current);
        return;
    }
    
    // No pick
    subsetsHelper(nums, current, depth+1);
    
    // Pick
    current.push_back(nums[depth]);
    subsetsHelper(nums, current, depth+1);
    current.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<int> cur;
    subsetsHelper(nums, cur, 0);
    return result;
}

int main(){

    
    vector<int> input = {1,2,3};
    vector<vector<int>> final_sets = subsets(input);

    cout << "[";
    for(int i=0; i< final_sets.size(); i++){
        cout << "[";
        for(int j=0; j< final_sets[i].size(); j++){
            cout << final_sets[i][j];
        }
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}