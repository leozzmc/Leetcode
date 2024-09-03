#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BT;

class TreeNode {
    public:
        int val;
        TreeNode *left, *right;
        TreeNode():val(0), left(nullptr), right(nullptr) {};
        TreeNode(int data): val(data), left(nullptr), right(nullptr) {};
        TreeNode(int data, TreeNode* leftNode, TreeNode* rightNode): val(data), left(leftNode),right(rightNode){};
    friend class BT;
};

class BT {
    public:
        TreeNode* root = new TreeNode;
        vector<vector<int>> result;
        BT():root(nullptr) {};
        BT(TreeNode* node): root(node) {};

        //member functions
        vector<vector<int>> zigzagLevelOrder(TreeNode* root);
};

vector<vector<int>> BT::zigzagLevelOrder(TreeNode* root){
    if(root == nullptr) return {};
    queue<TreeNode*> q;
    bool leftToRight = true;
    q.push(root);

    while(!q.empty()){
        int levelSize = q.size();
        vector<int> levelorderList(levelSize);
        
        for(int i = 0; i < levelSize; i++){
            TreeNode *current = q.front();
            q.pop();
            if(leftToRight) levelorderList[i] = current->val;
            else levelorderList[levelSize-i-1] = current->val;
            
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
        leftToRight = !leftToRight;
        result.push_back(levelorderList);
    }   
    return result;
}

int main(){
    //Test Tree1
    TreeNode *nodeA = new TreeNode(3);
    TreeNode *nodeB = new TreeNode(9);
    TreeNode *nodeC = new TreeNode(20);
    TreeNode *nodeD = new TreeNode(15);
    TreeNode *nodeE = new TreeNode(7);

    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeC->left = nodeD;
    nodeC->right = nodeE;

    BT T(nodeA);
    
    T.zigzagLevelOrder(T.root);
    
    // Print result
    for(auto it=T.result.begin(); it!=T.result.end(); ++it){
        for(auto j=it->begin(); j!=it->end(); ++j){
            cout << *j << " ";
        }
        cout << endl;
    }

    return 0;
}