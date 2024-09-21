#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;
vector<int> subArray;

void combinHelper(int depth, int K, int N ,vector<int> &result_Subarray, int start){
    if(depth == K){
        // append to result vector
        result.push_back(result_Subarray);
        return;
    }
    
    for(int i=start; i<=N; i++){
        result_Subarray.push_back(i);
        combinHelper(depth+1, K, N ,result_Subarray, i+1);
        result_Subarray.pop_back();
    }
    
}

vector<vector<int>> combine(int n, int k){
    combinHelper(0, k, n ,subArray, 1);
    return result;
}

int main(){
    
    vector<vector<int>> mainResult;
    mainResult = combine(4,2); 
    
    for(int i=0; i < mainResult.size();i++){
        for(int j=0; j< mainResult[i].size() ;j++){
            cout << mainResult[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}