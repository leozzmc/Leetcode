# include <iostream>
using namespace std;

class BT;
class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
        TreeNode():val(0),left(nullptr),right(nullptr) {};
        TreeNode(int x):val(x),left(nullptr),right(nullptr) {};
        TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode):val(x),left(leftNode),right(rightNode) {};
    friend class BT;
};

class BT{
    public:
        TreeNode *root;
        bool result =  true;
        TreeNode* prev = nullptr;
        
        BT():root(nullptr){};
        BT(TreeNode *node): root(node) {};

        //member function
        void dfs(TreeNode *root);
        bool isValidBST(TreeNode* root);
};

void BT::dfs(TreeNode *current){
    if(current==nullptr) return;
    dfs(current->left);
    cout << current->val << " " <<  endl;
   
    if(prev && prev->val >= current->val) result = false;
    prev = current;
    dfs(current->right);
}

bool BT::isValidBST(TreeNode* root){
    if(root==nullptr) return false;
    dfs(root);
    return result;
}

int main(){

    //Test Tree 1
    // TreeNode *nodeA = new TreeNode(2);
    // TreeNode *nodeB = new TreeNode(1);
    // TreeNode *nodeC = new TreeNode(3);

    // nodeA->left = nodeB;
    // nodeA->right = nodeC;

    // BT T(nodeA);

    //Test Tree 2
    // TreeNode *nodeA = new TreeNode(5);
    // TreeNode *nodeB = new TreeNode(1);
    // TreeNode *nodeC = new TreeNode(3);
    // TreeNode *nodeD = new TreeNode(4);
    // TreeNode *nodeE = new TreeNode(6);

    // nodeA->left = nodeB;
    // nodeA->right = nodeC;
    // nodeC->left = nodeD;
    // nodeC->right = nodeE;

    // BT T(nodeA);

    TreeNode *nodeA = new TreeNode(1);

    BT T(nodeA);

    cout << "\n Is valid: " << T.isValidBST(T.root) << endl;

    return 0;
}