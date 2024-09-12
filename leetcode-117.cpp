# include <iostream>
# include <queue>

using namespace std;

class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}

        Node* connect(Node* root);
};

Node* Node::connect(Node* root){
    if(root == NULL) return NULL;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int *level = q.size();
        for(int i = 0; i < level; i++){
            Node *current = q.front();
            q.pop();
            if(i == level-1){
                current->next = NULL;
            }
            else{
                current->next = q.front();
            }
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
    }
    return root;
}
int main(){

    // test input
    Node *nodeA = new Node(1);
    Node *nodeB = new Node(2);
    Node *nodeC = new Node(3);
    Node *nodeD = new Node(4);
    Node *nodeE = new Node(5);
    Node *nodeF = new Node(7);

    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->left = nodeD;
    nodeB->right = nodeE;
    nodeC->right = nodeF;


    return 0;
}