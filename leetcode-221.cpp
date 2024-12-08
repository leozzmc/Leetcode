#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix){
    if(matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    
    vector<vector<int>> dp(m , vector<int>(n, 0));
    int maxSide =0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == '1'){
                if(i == 0 || j==0) dp[i][j] = 1;
                else{
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;   
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide * maxSide;
}

int main(){

    //vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    vector<vector<char>> matrix = {{'1'}};
    cout << maximalSquare(matrix) << endl;
    return 0;
}