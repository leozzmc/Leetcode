#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Graph{
    private:
        int num_vertex;
        vector<vector<int>> adjList;
        int *label,  // 0: not found, 1: found, 2. removed
            *distance,  // 0: starting point, MAX_INT: vertex that cannot be found by the starting point
            *predecessor; // -1: no predecessor, starting point
    public:
        Graph(): num_vertex(0) {};
        Graph(int N): num_vertex(N){
            adjList.resize(num_vertex);
        };
        //member function
        void addEdgeList(int from, int to);
        void bfs(int start);
        
         // Getter functions for debugging
        int getNumVertex() const { return num_vertex; }
        int* getDistances() const { return distance; }
        int* getPredecessors() const { return predecessor; }
};

void Graph::addEdgeList(int from, int to){
    adjList[from].push_back(to);
}

void Graph::bfs(int start){

    // init the arrays
    label = new int[num_vertex];
    distance = new int[num_vertex];
    predecessor = new int[num_vertex];

    for(int i=0; i<num_vertex; i++){
        label[i] = 0;
        distance[i] = INT_MAX;
        predecessor[i] = -1;
    }

    queue<int> q;
    int i=start;

    for(int j=0; j<num_vertex; j++){
        if(label[i]==0){
            label[i]=1;
            distance[i]=0;
            predecessor[i]=-1;
            q.push(i);
            while(!q.empty()){
                int u = q.front();
                for(auto it=adjList[u].begin(); it!=adjList[u].end(); ++it){
                    if(label[*it]==0){
                        label[*it]=1;
                        distance[*it] = distance[u] + 1;
                        predecessor[*it] = u;
                        q.push(*it);
                    }
                }
                q.pop();
                label[u] = 2;
            }
        }
        i =j;
    }
}




int main(){

    Graph g1(8);

    g1.addEdgeList(0,1); g1.addEdgeList(0,2);
    g1.addEdgeList(1,0); g1.addEdgeList(1,3); g1.addEdgeList(1,4);
    g1.addEdgeList(2,0); g1.addEdgeList(2,5);
    g1.addEdgeList(3,1); g1.addEdgeList(3,4); g1.addEdgeList(3,6);g1.addEdgeList(3,7);
    g1.addEdgeList(4,1); g1.addEdgeList(4,3); g1.addEdgeList(4,5); g1.addEdgeList(3,7);
    g1.addEdgeList(5,2); g1.addEdgeList(5,4); g1.addEdgeList(5,6); 
    g1.addEdgeList(6,3); g1.addEdgeList(6,5); g1.addEdgeList(6,7);
    g1.addEdgeList(7,3); g1.addEdgeList(7,4); g1.addEdgeList(7,6);

    g1.bfs(0);

    for (int i = 0; i < g1.getNumVertex(); i++) {
        cout << "Distance[" << i << "]: " << g1.getDistances()[i] << " | ";
        cout << "Predecessor[" << i << "]: " << g1.getPredecessors()[i] << endl;
    }



    return 0;
}