#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;


class Graph {
    public:
        Graph(){};

        //member function
        void wallsAndGates(vector<vector<int>>& rooms);

};

void Graph::wallsAndGates(vector<vector<int>>& rooms){
    int m= rooms.size();
    int n= rooms[0].size();

    queue<pair<int, int>> q;
    int offsetRow[4] = {1,0,-1,0};
    int offsetCol[4] = {0,1,0,-1};

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(rooms[i][j]== 0 ){
                q.push({i,j});
                
            }
        }
    }
    
  
    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        for(int k=0; k<4; k++){
            int subRow = current.first + offsetRow[k];
            int subCol = current.second + offsetCol[k];

            if(subRow >= 0 && subRow < m && subCol >=0 && subCol < n  && rooms[subRow][subCol] == INT_MAX ){
                rooms[subRow][subCol] = rooms[current.first][current.second] +1;
                q.push({subRow,subCol});
                
            }

        }

    }
}


int main(){
    
    Graph g;

    vector<vector<int>> rooms = {
        {2147483647,-1,0,2147483647},
        {2147483647,2147483647,2147483647,-1},
        {2147483647,-1,2147483647,-1},
        {0,-1,2147483647,2147483647}
    };

    g.wallsAndGates(rooms);
    
    for(int i=0; i<rooms.size(); i++){
        for(int j=0; j<rooms[0].size();j++){
            cout << rooms[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}