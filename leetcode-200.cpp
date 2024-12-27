#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    private:
        vector<vector<char>> grid;
        int row, col;
        vector<vector<int>> visited; //0:unvisited, 1: founded, 2:visited
    public:
        Graph(){};
        Graph(int r, int c): row(r), col(c){
            grid.resize(row);
            for(int i=0; i<row; i++){
                grid[i].resize(col);
            }
        }

        //member functions
        int numIslands(vector<vector<char>>& grid);
        void dfs(int r, int c);
};

void Graph::dfs(int r, int c){
    if(r<0 || r>= grid.size() || c <0 || c>= grid[0].size() || grid[r][c]=='0' || visited[r][c]==1) return;
    
    visited[r][c] = 1;
    dfs(r+1,c);
    dfs(r-1,c);
    dfs(r,c+1);
    dfs(r,c-1);
}


int Graph::numIslands(vector<vector<char>>& grid){
    this->grid = grid;
    row = grid.size();
    col = grid[0].size();
    visited.resize(row, vector<int>(col,0));
    int count = 0;


    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(grid[i][j]=='1' && visited[i][j] == 0){
                dfs(i,j);
                count++;
            }
        }
    }
    return count;
}

int main(){

    // vector<vector<char>> grid={
    //     {'1','1','1','1','0'},
    //     {'1','1','0','1','0'},
    //     {'1','1','0','0','0'},
    //     {'0','0','0','0','0'}
    // };
    
    vector<vector<char>> grid={
      {'1','1','0','0','0'},
      {'1','1','0','0','0'},
      {'0','0','1','0','0'},
      {'0','0','0','1','1'}
    };
    
    Graph g(grid.size(), grid[0].size());

    cout << g.numIslands(grid) << endl; // Expected output: 1

    return 0;
}