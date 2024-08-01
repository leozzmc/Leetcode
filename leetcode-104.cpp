# include <iostream>
# include <vector>
# include <queue>

using namespace std;

class BinaryTree;

class TreeNode{
    public:
        int val;
        TreeNode *leftchild, *rightchild;

        TreeNode():val(0),leftchild(0),rightchild(0){};
        TreeNode(int x):val(x),leftchild(0),rightchild(0){};
        TreeNode(int x, TreeNode *left, TreeNode *right):val(x),leftchild(left),rightchild(right){};
    
    friend class BinaryTree;
};

class BinaryTree{
    public:
        TreeNode *root;
        //Constructor
        BinaryTree():root(0){};
        BinaryTree(TreeNode * node):root(node){};

        //member function
        void Levelorder();
        int maxDepth(TreeNode * root);
};



int BinaryTree::maxDepth(TreeNode * current){
    if(current == 0) return 0;

    int leftdepth = maxDepth(current->leftchild);
    int rightdepth = maxDepth(current->rightchild);
    //cout << root->val << " ";
    return max(leftdepth, rightdepth) + 1;
}


int main(){
     // Instanitate  all tree nodes
    TreeNode *nodeA = new TreeNode(1);
    TreeNode *nodeB = new TreeNode(2);
    TreeNode *nodeC = new TreeNode(3);
    TreeNode *nodeD = new TreeNode(4);
    TreeNode *nodeE = new TreeNode(5);

    nodeA->leftchild = nodeB;
    nodeB -> leftchild = nodeD;
    nodeA->rightchild = nodeC;
    nodeC->rightchild = nodeE;

    //Define root node
    BinaryTree T(nodeA);

    // input: root=  [3,9,20,null,null,15,7]
    // cout << "Levelorder: " ;
    // T.Levelorder();
   cout << "Leftdepth: " <<  T.maxDepth(T.root) << endl;
    
    

    return 0;
}