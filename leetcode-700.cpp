#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BTS;

class TreeNode {
    public:
        int val;
        TreeNode *left, *right;

        TreeNode(): val(0), left(nullptr), right(nullptr) {};
        TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
        TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode): val(x), left(leftNode), right(rightNode) {};
    friend class BST;
};

class BST {
    public:
        TreeNode *root = new TreeNode;
        BST(): root(nullptr) {};
        BST(TreeNode *node): root(node){};

        //member functions
        TreeNode* searchBST(TreeNode* root, int val);
};


TreeNode* BST::searchBST(TreeNode* root, int val){
    
    if(root == nullptr) return nullptr;
    
    if(root->val > val){
        return searchBST(root->left, val);
    }
    else if(root->val < val){
        return searchBST(root->right, val);
    }
    else{
        return root;
    }
}

int main(){

    // Test Tree1
    TreeNode *nodeA = new TreeNode(4);
    TreeNode *nodeB = new TreeNode(2);
    TreeNode *nodeC = new TreeNode(7);
    TreeNode *nodeD = new TreeNode(1);
    TreeNode *nodeE = new TreeNode(3);

    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->left = nodeD;
    nodeB->right = nodeE;

    BST T(nodeA);
    int value =2;

    cout << T.searchBST(T.root, value)->val << endl;


    return 0;
}