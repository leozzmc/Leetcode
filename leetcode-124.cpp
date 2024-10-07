#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class BT;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(): val(0), left(nullptr), right(nullptr) {};
        TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
        TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode): val(x), left(leftNode), right(rightNode) {};
        friend class BT;
};

class BT{
    public:
        TreeNode *root = new TreeNode;
        vector<int> nodeList;
        int max = 0;
        BT(): root(nullptr){};
        BT(TreeNode *node): root(node){};

        //member functions
        int maxPathSum(TreeNode* root);
        int maxPathSumHelper(TreeNode* root, int &globalMax);
};


int BT::maxPathSumHelper(TreeNode* root, int &globalMax){
    if(root == nullptr) return 0;
    
    int leftMax = max(0, maxPathSumHelper(root->left, globalMax));
    int rightMax = max(0, maxPathSumHelper(root->right, globalMax));
    int currentMax = root->val + leftMax + rightMax;
    
    globalMax = max(currentMax, globalMax);
    return root->val + max(leftMax, rightMax);
}

int BT::maxPathSum(TreeNode* root){
    int globalMax = INT_MIN; 
    return maxPathSumHelper(root,globalMax);
}


int main(){

    // Construct BinaryTree
    TreeNode *nodeA = new TreeNode(-10);
    TreeNode *nodeB = new TreeNode(9);
    TreeNode *nodeC = new TreeNode(20);
    TreeNode *nodeD = new TreeNode(15);
    TreeNode *nodeE = new TreeNode(7);

    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeC->left = nodeD;
    nodeC->right = nodeE;

    BT T(nodeA);

    cout << T.maxPathSum(T.root);


    return 0;
}