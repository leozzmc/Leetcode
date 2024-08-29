# include <iostream>
# include <vector>
#include <algorithm>
using namespace std;

class BT;

class TreeNode {
    public:
        int val;
        TreeNode *left, *right;

        TreeNode(): val(0), left(nullptr), right(nullptr) {};
        TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
        TreeNode (int x, TreeNode *leftNode, TreeNode *rightNode): val(x), left(leftNode), right(rightNode){};
    friend class BT;
};

class BT{
    public:
        TreeNode *root;
        vector<int> nodes;
        vector<int> nodeDifferences;
        vector<int>::iterator result;

        BT(): root(nullptr) {};
        BT(TreeNode *node): root(node) {};

        //member functions
        void inorder(TreeNode *current);
        int getMinimumDifference(TreeNode* root);
};

void BT::inorder(TreeNode *current){
    if(current== nullptr) return;
    inorder(current->left);
    nodes.push_back(current->val);
    inorder(current->right);
}


int BT::getMinimumDifference(TreeNode* root){
    if(root == nullptr) return 0;
    inorder(root);
    for(int i=1; i< nodes.size(); i++){
        nodeDifferences.push_back(abs(nodes[i]-nodes[i-1]));
    }
    result = min_element(nodeDifferences.begin(), nodeDifferences.end());
    return *result;
}


int main(){

    //Test Tree 1
    // TreeNode *nodeA = new TreeNode(4);
    // TreeNode *nodeB = new TreeNode(2);
    // TreeNode *nodeC = new TreeNode(6);
    // TreeNode *nodeD = new TreeNode(1);
    // TreeNode *nodeE = new TreeNode(3);
    
    // nodeA->left = nodeB;
    // nodeA->right = nodeC;
    // nodeB->left = nodeD;
    // nodeB->right = nodeE;

    // BT T(nodeA);

    //Test Tree 2
    // TreeNode *nodeA = new TreeNode(1);
    // TreeNode *nodeB = new TreeNode(0);
    // TreeNode *nodeC = new TreeNode(48);
    // TreeNode *nodeD = new TreeNode(12);
    // TreeNode *nodeE = new TreeNode(49);
    
    // nodeA->left = nodeB;
    // nodeA->right = nodeC;
    // nodeC->left = nodeD;
    // nodeC->right = nodeE;

    // BT T(nodeA);
    
    //Test Tree 3
    // TreeNode *nodeA = new TreeNode(1);
    // TreeNode *nodeB = new TreeNode(5);
    // TreeNode *nodeC = new TreeNode(3);
    
    // nodeA->right = nodeB;
    // nodeB->left = nodeC;

    // BT T(nodeA);

    //Test Tree 4
    TreeNode *nodeA = new TreeNode(236);
    TreeNode *nodeB = new TreeNode(104);
    TreeNode *nodeC = new TreeNode(701);
    TreeNode *nodeD = new TreeNode(227);
    TreeNode *nodeE = new TreeNode(911);
    
    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->right = nodeD;
    nodeC->left = nodeE;
    

    BT T(nodeA);



    // Testing
    cout << T.getMinimumDifference(T.root) << endl;
    
    // for(auto it=T.nodeDifferences.begin(); it!=T.nodeDifferences.end(); ++it){
    //     cout << *it << " ";
    // }
    // cout << endl;
    
    

    return 0;
}