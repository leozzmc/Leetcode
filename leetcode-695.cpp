#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Graph{
    private:
        vector<vector<int>> visited; // 0: unvisited, 1: visited

    public:
        Graph() = default;


        //member function
        int maxAreaOfIsland(vector<vector<int>>& grid);
        int dfs(vector<vector<int>> &grid, int row, int col);
};


int Graph::dfs(vector<vector<int>> &grid, int row, int col){
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || visited[row][col] == 1 || grid[row][col] == 0) return 0;

    visited[row][col] = 1;
    int sum = 1;

    int offsetRow[4] = {1,0,-1,0};
    int offsetCol[4] = {0,1,0,-1};
    for(int k=0; k<4; k++){
        sum += dfs(grid, row+offsetRow[k], col+offsetCol[k]);
    }
    return sum;
}

int Graph::maxAreaOfIsland(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();

    visited.resize(m, vector<int>(n,0));
    int  maxIslandArea = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==1 && visited[i][j] ==0){
                int currentArea = dfs(grid, i,j);
                maxIslandArea = max(maxIslandArea, currentArea );
            }
        }
    }
    return maxIslandArea;
}

int main(){

    vector<vector<int>> grid {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    
    Graph g;

    cout << g.maxAreaOfIsland(grid) << endl;

    return 0;
}

