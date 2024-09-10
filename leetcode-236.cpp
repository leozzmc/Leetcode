# include <iostream>
# include <vector>

using namespace std;

class BT;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
        TreeNode():val(0), left(nullptr), right(nullptr) {};
        TreeNode(int x):val(x), left(nullptr), right(nullptr) {};
        TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode):val(0), left(leftNode), right(rightNode) {};
    friend class BT;
};

class BT{
    public:
        TreeNode *root = new TreeNode;
        TreeNode *result =nullptr;
        BT(): root(nullptr) {};
        BT(TreeNode *node):root(node) {};

        //member functions
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
       
};


TreeNode* BT::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==nullptr || root == p || root == q){
        return root;
    }
    
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    
    if(left!= nullptr && right!=nullptr) return root;
    if(left!=nullptr && right==nullptr ) return left;
    if(left==nullptr && right!=nullptr) return right;
    return nullptr;
}



int main(){
    //Test1
    // TreeNode *nodeA = new TreeNode(3);
    // TreeNode *nodeB = new TreeNode(5);
    // TreeNode *nodeC = new TreeNode(1);
    // TreeNode *nodeD = new TreeNode(6);
    // TreeNode *nodeE = new TreeNode(2);
    // TreeNode *nodeF = new TreeNode(0);
    // TreeNode *nodeG = new TreeNode(8);
    // TreeNode *nodeH = new TreeNode(7);
    // TreeNode *nodeI = new TreeNode(4);

    // nodeA->left = nodeB;
    // nodeA->right = nodeC;
    // nodeB->left = nodeD;
    // nodeB->right = nodeE;
    // nodeC->left = nodeF;
    // nodeC->right = nodeG;
    // nodeE->left = nodeH;
    // nodeE->right = nodeI;

    // BT T(nodeA);
    
    //Test2
    TreeNode *nodeA = new TreeNode(-1);
    TreeNode *nodeB = new TreeNode(0);
    TreeNode *nodeC = new TreeNode(3);
    TreeNode *nodeD = new TreeNode(-2);
    TreeNode *nodeE = new TreeNode(4);
    TreeNode *nodeF = new TreeNode(8);

    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->left = nodeD;
    nodeB->right = nodeE;
    nodeD->left = nodeF;

  

    BT T(nodeA);
    
    TreeNode *p = nodeF;
    TreeNode *q = nodeE;

    //Test output
    cout << "Lowest Common Ancestor: " << T.lowestCommonAncestor(T.root, p,q)->val << endl;
    
    return 0;
}