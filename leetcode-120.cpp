#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> dp;
int helper(vector<vector<int>>& triangle, int row, int index ){
    if(row == triangle.size()){
        return 0;
    }
    
    if(dp[row][index]!=INT_MAX) return dp[row][index];
    
    int r1 = helper(triangle, row+1, index);
    int r2 = helper(triangle, row+1, index+1); 
    dp[row][index] = triangle[row][index] + min(r1, r2);
    
    return dp[row][index];
    
}

int minimumTotal(vector<vector<int>>& triangle){

    dp = vector<vector<int>>(triangle.size(), vector<int>(triangle.size(), INT_MAX));
    return helper(triangle, 0, 0);
}

int main(){
    vector<vector<int>> triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
    // vector<vector<int>> triangle={{-11}};
    cout << minimumTotal(triangle) << endl;

    return 0;
}