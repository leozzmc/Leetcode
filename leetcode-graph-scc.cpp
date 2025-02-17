#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

class Graph {
    private:
        int num_vertex;
        vector<list<int>> AdjList;
        void DFSVisit(int v, vector<bool> &visited, stack<int> &finishStack);
        void DFSVisitSCC(int v, vector<bool> &visited, vector<int> &component);

    public:
        Graph(int N): num_vertex(N) {
            AdjList.resize(num_vertex);
        }
        void AddEdgeList(int from, int to);
        Graph GraphTranspose();
        void FindSCCs();

};

void Graph::AddEdgeList(int from, int to){
    AdjList[from].push_back(to);
}

void Graph::DFSVisit(int v, vector<bool> &visited, stack<int> &finishStack){
    visited[v] = true;
    for(int neighbor: AdjList[v]){
        if(!visited[neighbor]){
            DFSVisit(neighbor, visited, finishStack);
        }
    }
    finishStack.push(v);
}

void Graph::DFSVisitSCC(int v, vector<bool> &visited, vector<int> &component){
    visited[v] = true;
    component.push_back(v);
    for(int neighbor: AdjList[v]){
        if(!visited[neighbor]){
            DFSVisitSCC(neighbor, visited, component);
        }
    }
}

Graph Graph::GraphTranspose(){
    Graph gT(num_vertex);
    for(int i=0; i<num_vertex; i++){
        for(int neighbor: AdjList[i]){
            gT.AddEdgeList(neighbor, i);
        }
    }
    return gT;
}

// Kosaraju's Algorithm to find SCCs
void Graph::FindSCCs(){
    stack<int> finishStack;
    vector<bool> visited(num_vertex, false);

    // First DFS to get the finish order
    for(int i=0; i< num_vertex;i++){
        if(!visited[i]){
            DFSVisit(i, visited, finishStack);
        }
    }


    // Get transposed graph
    Graph gT = GraphTranspose();

    //Second DFS to find SCCs in finishStack order
    // reinit visited array
    fill(visited.begin(), visited.end(), false);

    cout << "Strongly Connected Components: \n";
    while(!finishStack.empty()){
        int v = finishStack.top();
        finishStack.pop();

        if(!visited[v]){
            vector<int> components;
            gT.DFSVisitSCC(v, visited, components);
            for(int node: components){
                cout << node << " ";
            }
            cout << endl;
        }
    }
}

int main(){

    //Test 
    Graph g(9);
    g.AddEdgeList(0, 1);
    g.AddEdgeList(1, 2);
    g.AddEdgeList(1, 4);
    g.AddEdgeList(2, 0);
    g.AddEdgeList(2, 3);
    g.AddEdgeList(2, 5);
    g.AddEdgeList(3, 2);
    g.AddEdgeList(4, 5);
    g.AddEdgeList(4, 6);
    g.AddEdgeList(5, 4);
    g.AddEdgeList(5, 6);
    g.AddEdgeList(5, 7);
    g.AddEdgeList(6, 7);
    g.AddEdgeList(7, 8);
    g.AddEdgeList(8, 6);

    g.FindSCCs();

    return 0;
}