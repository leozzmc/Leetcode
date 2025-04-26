#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BT;

class TreeNode {
    public:
        int val;
        TreeNode *left, *right;

        TreeNode(): val(0), left(nullptr), right(nullptr) {};
        TreeNode(int nodeValue): val(nodeValue), left(nullptr), right(nullptr) {};
        TreeNode(int nodeValue, TreeNode *leftNode, TreeNode *rightNode): val(0), left(leftNode), right(rightNode) {};

    friend class BT;
};

class BT{
    TreeNode *root = new TreeNode();
    bool isB = true;

    BT(): root(nullptr){};
    BT(TreeNode *node): root(node){};
    
    // member functions
    bool isBalanced(TreeNode *node);
    int dfs(TreeNode *node);

};

int BT::dfs(TreeNode *node){
    if(node == nullptr) return 0;

    int l_subtree = dfs(node->left);
    int r_subtree = dfs(node->right);
    if (abs(l_subtree - r_subtree) > 1) isB = false;

    return max(l_subtree, r_subtree) + 1;
}

bool BT::isBalanced(TreeNode *root){
    if(root==nullptr) return true;
    dfs(root);
    return isB;
}

int main(){

    //Test -1
    TreeNode *nodeA = new TreeNode(3);
    TreeNode *nodeB = new TreeNode(9);
    TreeNode *nodeC = new TreeNode(20);
    TreeNode *nodeD = new TreeNode(15);
    TreeNode *nodeE = new TreeNode(7);

    nodeA -> left = nodeB;
    nodeA -> right = nodeC;
    nodeC -> left = nodeD;
    nodeC -> right = nodeE;

    BT T(nodeA);

    cout << T.isBalanced(T.root) << endl;


    return 0;
}