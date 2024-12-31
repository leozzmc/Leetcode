#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;



class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node){

    if(node==nullptr) return nullptr;

    // Step1: DFS traveral for constructing an map
    unordered_map<Node*, Node*> nodeMap;
    queue<Node*> nodeToVisit;
    nodeToVisit.push(node);
    
    nodeMap[node] = new Node(node->val);

    while(!nodeToVisit.empty()){
        Node* current = nodeToVisit.front();
        nodeToVisit.pop();

        for(Node* n : current->neighbors){
            if(nodeMap.find(n) == nodeMap.end()){
                nodeMap[n] = new Node(n->val);
                nodeToVisit.push(n);
            }
            // Update the adjlist of current node to the corresponding new nodes
            nodeMap[current]->neighbors.push_back(nodeMap[n]);
        }
    }
    // Step2: Recreate new nodes from the map
    return nodeMap[node];
}

int main(){

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Node* clonedGraph = cloneGraph(node1);
    cout << "Original Node: " << node1->val << endl;
    cout << "Cloned Node: " << clonedGraph->val << endl;



    return 0;
}