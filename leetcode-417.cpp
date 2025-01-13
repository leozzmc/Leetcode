#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


void bfs(queue<pair<int, int>>& q, vector<vector<int>> &heights, vector<vector<bool>> &ocean){
    
    int offsetRow[4] = {1,0,-1,0};
    int offsetCol[4] = {0,1,0,-1};

    while(!q.empty()){
        pair<int,int> current = q.front();
        q.pop();
        for(int k=0; k<4; k++){
            int subRow = current.first + offsetRow[k];
            int subCol = current.second + offsetCol[k];

            if(subRow >=0 && subRow < heights.size() && subCol >=0 && subCol < heights[0].size() && heights[current.first][current.second] <= heights[subRow][subCol] && !ocean[subRow][subCol]){
                ocean[subRow][subCol] = true;
                q.push({subRow, subCol});
            }
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));

    queue<pair<int, int>> pacificQueue;
    queue<pair<int, int>> atlanticQueue;

    // init the pacific edge
    for(int i=0; i<m; i++){
        pacificQueue.push({i,0});
        atlanticQueue.push({i,n-1});
        pacific[i][0] = true;
        atlantic[i][n-1] = true;
    }

    //init the atlantic edge
    for(int i=0; i<n; i++){
        pacificQueue.push({0,i});
        atlanticQueue.push({m-1,i});
        pacific[0][i] =true;
        atlantic[m-1][i] = true;
    }

    // Conduct BFS to PacificQueue
    bfs(pacificQueue, heights, pacific);

    // Conduct BFS to AtlanticQueue
    bfs(atlanticQueue, heights, atlantic);

    // Retrive the intersection of the two vectors.
    vector<vector<int>> result;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(pacific[i][j] && atlantic[i][j]) result.push_back({i,j});
        }
    }
    return result;

}

int main() {
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    vector<vector<int>> result = pacificAtlantic(heights);

    cout << "Coordinates where water can flow to both oceans:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << " " << result[i][1] << endl;
    }

    return 0;
}
