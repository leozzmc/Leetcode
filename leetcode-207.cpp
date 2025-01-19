#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<int>> &adjMatrix, vector<int> &visited, vector<int> &recStack, int node){
        if(!visited[node]){
            visited[node] = 1;
             
            // Add the node to the recursion stack
            recStack[node] = 1;

            for(int neighbor = 0; neighbor < adjMatrix.size(); neighbor++){
                if(adjMatrix[node][neighbor] == 1){
                    if(!visited[neighbor] && dfs(adjMatrix, visited, recStack, neighbor) || recStack[neighbor]){
                        return true; // cycle detected
                    }
                }
            }
        }
         // Remove the node from the recursion stack
        recStack[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m = numCourses;
        vector<vector<int>> adjMatrix(m, vector<int>(m, 0));
        vector<int> visited(m, 0); //0: unvisited
        vector<int> recStack(m, 0); // 0: not in recursion stack
 
        // transform prerequisites into adjMatrix
        for(auto &prerequisite : prerequisites){
            adjMatrix[prerequisite[1]][prerequisite[0]] = 1; // Directed edge from prerequisite[1] to prerequisite[0]
        }

        // Check for cycle in the graph
        for(int i=0; i< m; i++){
            if(!visited[i]){
                if(dfs(adjMatrix, visited, recStack, i)){
                    return false;
                }

            }
        }

        return true;

    }
};