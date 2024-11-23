#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    if(obstacleGrid[0][0] == 0)dp[0][0] = 1;
    else dp[0][0] =0;
    

    
    for(int i=1; i<m; i++){
        if(obstacleGrid[i][0] == 0 && dp[i-1][0] == 1)dp[i][0] = 1;
        else dp[i][0] =0;
    }
    
     for(int j=1; j<n; j++){
        if(obstacleGrid[0][j] == 0 && dp[0][j-1]==1) dp[0][j] = 1;
        else dp[0][j] = 0;
    }
    
    for(int i=1; i<m;i++){
        for(int j=1; j<n; j++){
            if(obstacleGrid[i][j]== 0){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}

int main(){
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}