class Solution {
    public:
        bool dfs(vector<bool> &visited, vector<vector<int>> &adjList, int prevNode, int node){
            visited[node] = true;
            for(int neighbor: adjList[node]){
                if(neighbor == prevNode) continue;
                if(visited[neighbor] || dfs(visited, adjList, node, neighbor)){
                    return true;
                }
            }
            return false;
        }
        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            int n = edges.size();
            vector<vector<int>> adjList;
            adjList.resize(n+1);
            
            for(auto edge: edges){
                // construct adjacency list
                adjList[edge[0]].push_back(edge[1]);
                adjList[edge[1]].push_back(edge[0]);
    
                vector<bool> visited(n+1, false);
                if(dfs(visited, adjList,-1, edge[0])){
                    // cycle detected, return redundant edge
                    return edge;
                }
            }
            return {};
        }
    };