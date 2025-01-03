#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Graph{
    public:
        Graph(){};
        //member function
        int orangesRotting(vector<vector<int>>& grid);
};

int Graph::orangesRotting(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    int minute = 0;
    int freshCount = 0;
    int offsetRow[4] = {1,0,-1,0};
    int offsetCol[4] = {0,1,0,-1};
    queue<pair<int,int>> q;

    for(int i=0; i<m;i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 2){
                q.push({i,j});
            }
            else if(grid[i][j]==1){
                freshCount++;
            }
        }
    }

    while(!q.empty() && freshCount >0){
       int size = q.size();
       for(int i =0; i<size;i++){
            pair<int,int> current = q.front();
            q.pop();
            for(int k=0; k<4; k++){
                int subRow = current.first + offsetRow[k];
                int subCol = current.second + offsetCol[k];
    
                if(subCol >=0 && subCol < n && subRow >=0 && subRow < m && grid[subRow][subCol]==1){
                    grid[subRow][subCol]=2;
                    freshCount--;
                    q.push({subRow,subCol});
                }
            }
       }
       minute++;

    }
    return freshCount == 0 ? minute : -1;
}


int main(){
    
    Graph g;
    vector<vector<int>> grid={
        {2,1,1},
        {1,1,1},
        {0,1,2}
    };
    cout << g.orangesRotting(grid) << endl;
    
    return 0;
}