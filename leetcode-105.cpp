# include <iostream>
using namespace std;

class BT;
class TreeNode{
    public:
        int val;
        TreeNode *left,*right;
        TreeNode():val(0),left(nullptr),right(nullptr) {};
        TreeNode(int x):val(x),left(nullptr),right(nullptr) {};
        TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode):val(x),left(leftNode),right(rightNode) {};
    friend class BT;
};

class BT{
    public:
        TreeNode *root = new TreeNode;
        BT():root(nullptr) {};
        BT(TreeNode *node):root(node) {};

        //memeber functions
        void preorder(TreeNode *current);

        
};

void BT::preorder(TreeNode *current){
    if(current==NULL) return;
    cout << current->val << " ";
    preorder(current->left);
    preorder(current->right);
}

int main(){

    TreeNode *nodeA = new TreeNode(1);
    TreeNode *nodeB = new TreeNode(2);
    TreeNode *nodeC = new TreeNode(3);
    TreeNode *nodeD = new TreeNode(4);
    TreeNode *nodeE = new TreeNode(5);
    TreeNode *nodeF = new TreeNode(6);
    TreeNode *nodeG = new TreeNode(7);

    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->left = nodeD;
    nodeB->right = nodeE;
    nodeC->right nodeF;
    nodeE ->left = nodeG;

    BT T(nodeA);

    cout << "pre-order traversal" << endl;
    T.preorder(T.root);


    return 0;
}