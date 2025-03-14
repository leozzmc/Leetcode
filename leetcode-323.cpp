#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
    public:
        void dfs(vector<vector<int>> &adjList, vector<bool> &visited, int node){
            if(visited[node]) return;

            visited[node] = true;
            
            for(int neighbor: adjList[node]){
                dfs(adjList, visited, neighbor);
            }
    

        }

        int countComponents(int n, vector<vector<int>>& edges) {
            // Define a adjacency list
            vector<vector<int>> adjList;
            vector<bool> visited(n, false);
            int sum = 0;

            adjList.resize(n);
            // Construct adjacency list
            for(int i=0; i< edges.size();i++){
                adjList[edges[i][0]].push_back(edges[i][1]);
                adjList[edges[i][1]].push_back(edges[i][0]);
            }

            // Perform DFS, and calculate the number of connected components
            for(int i=0; i<n; i++){
                if(!visited[i]){
                    dfs(adjList, visited, i);
                    sum++;
                }
            }
            return sum;
        }
};


int main(){
    return 0;
}