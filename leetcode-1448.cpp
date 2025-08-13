# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
using namespace std;


class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    int nodeCount = 0;
    int goodNodes(TreeNode* root);
    void dfs(TreeNode *root, int max);
};

void TreeNode::dfs(TreeNode *root, int max){
    if(root==nullptr) return;
    if(root->val >= max){
        max= root->val;
        nodeCount++;
    }

    dfs(root->left, max);
    dfs(root->right, max);
}

int TreeNode::goodNodes(TreeNode* root) {
    dfs(root, INT_MIN);
    return nodeCount;
}

int main(){

    // test tree
    TreeNode *nodeA = new TreeNode(3);
    TreeNode *nodeB = new TreeNode(1);
    TreeNode *nodeC = new TreeNode(4);
    TreeNode *nodeD = new TreeNode(3);
    TreeNode *nodeE = new TreeNode(1);
    TreeNode *nodeF = new TreeNode(5);

    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->left = nodeD;
    nodeC->left = nodeE;
    nodeC->right = nodeF;
    
    TreeNode BT;

    cout << "Good nodes count:" << BT.goodNodes(nodeA) << endl;

    return 0;
}