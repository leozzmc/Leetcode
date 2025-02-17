#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<list<int>> AdjList;
    bool hasCycle(int v, vector<int> &visited, stack<int> &finishStack){
        visited[v] = 1;
        for(int neighbor: AdjList[v]){
            if(visited[neighbor] == 1) return true;
            if(visited[neighbor]==0 && hasCycle(neighbor, visited, finishStack)) return true;
        }
        visited[v] = 2;
        finishStack.push(v);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int m = numCourses;
        vector<int> visited(m, 0); // 0:unvisited, 1:visiting, 2: finished
        stack<int> finishStack; 

        // Construct Adj list
        AdjList.resize(m);
        for(auto &pre: prerequisites){
            AdjList[pre[1]].push_back(pre[0]);
        }

        // First DFS
        for(int i=0; i<m;i++){
            if(visited[i]== 0 ){
                if(hasCycle(i, visited, finishStack)) return {};
            }
        }

        // Push finished node to stack
       vector<int> returnVector;
       while(!finishStack.empty()){
            int  vertex = finishStack.top();
            finishStack.pop();
            returnVector.push_back(vertex);
       }
       return returnVector;
    }
};

int main(){
    return 0;
}