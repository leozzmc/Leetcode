#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;

void combinationHelper(int currentVal, vector<int> &candidate, int target, vector<int> &subResults, int start){
    if(currentVal == target){
        result.push_back(subResults);
        return;
    }
    else if(currentVal < target){
        for(int i=start; i< candidate.size();i++){
            subResults.push_back(candidate[i]);
            //currentVal += candidate[i];
            combinationHelper(currentVal + candidate[i], candidate, target,subResults, i);
            subResults.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<int> sub;
    combinationHelper(0,candidates, target, sub, 0);
    return result;
}


int main(){

    vector<int> candidate = {2,3,5};
    vector<vector<int>> finalResult;
    int target = 8;
    finalResult = combinationSum(candidate, target);

    for(int i=0; i< finalResult.size(); i++){
        for(int j=0; j< finalResult[i].size(); j++){
            cout << finalResult[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}