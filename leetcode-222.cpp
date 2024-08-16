# include <iostream>
# include <queue>

using namespace std;

class BT;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
        TreeNode():val(0), left(nullptr), right(nullptr) {};
        TreeNode(int x):val(x), left(nullptr), right(nullptr) {};
        TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode):val(x), left(leftNode), right(rightNode) {};
    friend class BT;
};

class BT{
    public:
        TreeNode *root = new TreeNode;
        int counter=0;
        int leaf_count =0;
        
        BT(): root() {};
        BT(TreeNode *node):root(node){};

        //member functions
        int countNodes(TreeNode* root);

        // int inorder(TreeNode * current);

};

// must run with complexity less than O(N)
// If you know the height of the tree, you know the upper bound of the number of nodes
int BT::countNodes(TreeNode* root){
    TreeNode *current = root;
    if(current==nullptr) return 0;
    
    int leftheight=0;
    TreeNode *leftNode = root;
    while(leftNode!=nullptr){
        leftNode=leftNode->left;
        leftheight++;
    }

    
    int rightheight=0;
    TreeNode *rightNode = root;
    while(rightNode!=nullptr){
        rightNode=rightNode->right;
        rightheight++;
    }
    
    // perfect binary tree, the number of nodes is 2^0+2^1+2...+2^h (h is the height of tree) = 2^h -1
    if(leftheight == rightheight){
        return (1 << leftheight) -1;
    }
    else{
        return countNodes(current->left) + countNodes(current->right) +1;
    }
}



int main(){

    TreeNode *nodeA = new TreeNode(1);
    TreeNode *nodeB = new TreeNode(2);
    TreeNode *nodeC = new TreeNode(3);
    TreeNode *nodeD = new TreeNode(4);
    TreeNode *nodeE = new TreeNode(5);
    TreeNode *nodeF = new TreeNode(6);

    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->left = nodeD;
    nodeB->right = nodeE;
    nodeC->left = nodeF;

    BT T(nodeA);
    // cout << "Tree Height:" << T.countNodes(T.root) << endl;
    cout << "Inorder Traversal: " << endl;
    cout << T.countNodes(T.root);
    
    

    return 0;
}