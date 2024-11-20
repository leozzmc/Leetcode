#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<int>> dp;
int helper(vector<vector<int>>& grid, int i, int j){
    if (i >= grid.size() || j >= grid[0].size()) return INT_MAX;
    if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];

    if(dp[i][j]!=INT_MAX) return dp[i][j];

    int r1 = helper(grid,i+1,j);
    int r2 = helper(grid,i,j+1);
    dp[i][j] = grid[i][j] + min(r1, r2);
    return dp[i][j];
}

int minPathSum(vector<vector<int>>& grid){
    dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), INT_MAX));
    return helper(grid,0,0);
}

int main(){
    // vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int>> grid = {{1,2,3},{4,5,6}};
    cout << minPathSum(grid) << endl; 

    return 0;
}