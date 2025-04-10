#include <iostream>
#include <vector>

using namespace std;

class BT;
class TreeNode {
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(): val(0), left(nullptr), right(nullptr){}; 
        TreeNode(int value): val(value), left(nullptr), right(nullptr){}; 
        TreeNode(int value, TreeNode *leftNode, TreeNode *rightNode): val(0), left(leftNode), right(rightNode){}; 
    friend class BT;
};

class BT {
    public:
        TreeNode *root;
        int maxDiameter = 0;
        
        BT():root(){};
        BT(TreeNode *node): root(node){};
        // member functions
        int diameterOfBinaryTree(TreeNode* root);
        int height(TreeNode *node);
};

int BT::height(TreeNode* node) {
    if(node==nullptr) return 0;
    // Find the diameter of left subtree 
    int leftDiameter = height(node->left);
    // FInd the diameter of right subtree
    int rightDiameter = height(node->right);

    maxDiameter = max(maxDiameter, leftDiameter+rightDiameter);

    return 1+max(leftDiameter, rightDiameter);
}

int BT::diameterOfBinaryTree(TreeNode* root){
    if(root->left == nullptr && root->right==nullptr) return 0;
    if(root == nullptr) return 0;
    maxDiameter = 0;
    height(root);
    return abs(maxDiameter);
}



int main(){

    // define a example tree
    TreeNode *nodeA = new TreeNode(1);
    TreeNode *nodeB = new TreeNode(2);
    TreeNode *nodeC = new TreeNode(3);
    TreeNode *nodeD = new TreeNode(4);
    TreeNode *nodeE = new TreeNode(5);

    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->left = nodeD;
    nodeB->right = nodeE;

    BT T(nodeA);

    // Have to return diameter of a tree
    cout<< T.diameterOfBinaryTree(T.root);

    return 0;
}