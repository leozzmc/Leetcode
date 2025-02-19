#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
    
        bool hasCycle(vector<int> &visited, vector<list<int>> &adjList, int v, int parrent){
            visited[v]= 1;
            for(auto neighbor: adjList[v]){
                if(neighbor == parrent) continue;
                if(visited[neighbor]==1) return true;
                if(visited[neighbor]==0 && hasCycle(visited, adjList, neighbor, v)) return true;
            }
            visited[v] =2;
            return false; 
        }
    
        bool validTree(int n, vector<vector<int>>& edges) {
            vector<int> visited(n, 0); // 0: unvisited, 1: visiting, 2: finish
            vector<list<int>> adjList(n);
    
            // Turn edges into adj list
            for(auto edge: edges){
                adjList[edge[0]].push_back(edge[1]);
                adjList[edge[1]].push_back(edge[0]);
            }
    
            // It's a tree, so giving root node, it will traverse whole node in the tree
            if(hasCycle(visited, adjList, 0 , -1)) return false;
    
            // It it's a tree, all node should finish visiting
    
            for(int i=0; i<n; i++){
                if(visited[i]!=2 ) return false;
            }
    
            return true;
        }
    };

int main(){
    return 0;
}