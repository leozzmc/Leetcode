#include <iostream>
#include <vector>
#include <list>
#include <iomanip>

using namespace std;

class Graph{
    private:
        int num_vertex;
        vector<list<int>> adjList;
        int *visited,  // 0: Not visited, 1: Visited, not finished, 2: Finished 
            *predecessor,
            *discover,
            *finish;

    public:
        Graph(): num_vertex(0){};
        Graph(int N): num_vertex(N){
            adjList.resize(num_vertex);
        };

        // Member functions
        void addEdgeList(int from, int to);
        void dfs(int start);
        void dfsVisit(int vertex, int &time);
        void printDiscoverAndFinishTimes();
};

void Graph::addEdgeList(int from, int to){
    adjList[from].push_back(to);
}

void Graph::dfs(int start){
    // Initialize arrays
    visited = new int[num_vertex];
    predecessor = new int[num_vertex];
    discover = new int[num_vertex];
    finish = new int[num_vertex];
    int time = 0;

    for(int i = 0; i < num_vertex; i++){
        visited[i] = 0;
        predecessor[i] = -1;
        discover[i] = 0;
        finish[i] = 0;
    }

    // If vertices are unvisited, then visit them
    for(int i = start; i < num_vertex; i++){
        if(visited[i] == 0){
            dfsVisit(i, time);
        }
    }
}

void Graph::dfsVisit(int vertex, int &time){
    visited[vertex] = 1;
    discover[vertex] = ++time;
    for(auto it = adjList[vertex].begin(); it != adjList[vertex].end(); ++it){
        if(visited[*it] == 0){
            predecessor[*it] = vertex;
            dfsVisit(*it, time);
        }
    }
    visited[vertex] = 2;
    finish[vertex] = ++time;
}

void Graph::printDiscoverAndFinishTimes(){
    cout << "Vertex\tDiscover\tFinish" << endl;
    for(int i = 0; i < num_vertex; i++){
        cout << i << "\t\t" << discover[i] << "\t\t" << finish[i] << endl;
    }
}

int main(){

    Graph g2(8);

    g2.addEdgeList(0, 1); g2.addEdgeList(0, 2);
    g2.addEdgeList(1, 3);
    g2.addEdgeList(2, 5);
    g2.addEdgeList(3, 7);
    g2.addEdgeList(4, 1); g2.addEdgeList(4, 3); g2.addEdgeList(4, 7);
    g2.addEdgeList(5, 4); g2.addEdgeList(5, 6);
    g2.addEdgeList(6, 3); g2.addEdgeList(6, 7);

    g2.dfs(0);
    g2.printDiscoverAndFinishTimes();

    return 0;
}
