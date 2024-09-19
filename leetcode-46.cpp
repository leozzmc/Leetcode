#include <iostream>
#include <vector>
using namespace std;

vector<int> numList;
vector<vector<int>> final_result;

void permutehelper(int depth, vector<int> &temp_result, int MAX_DEPTH){
        if (depth == MAX_DEPTH){
            final_result.push_back(temp_result);
            return;
        }
        for(int i=0;i<numList.size(); i++){
            temp_result.push_back(numList[i]);
            int restore = numList[i];
            numList.erase(numList.begin()+i);
            permutehelper(depth+1, temp_result, MAX_DEPTH);
            temp_result.pop_back();
            numList.insert(numList.begin()+i, restore);
            restore =0;
            
        }
}

vector<vector<int>> permute(vector<int>& nums){
        vector<int> subResult;
        numList = nums;
        int max_depth = nums.size();
        permutehelper(0, subResult, max_depth);
        return final_result;
}

int main(){
    vector<int> num = {1,2,3};
    permute(num);

    // Print result
    for(int i=0; i< final_result.size(); i++){
        for(int j=0; j< final_result[i].size(); j++){
            cout << final_result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}