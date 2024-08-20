# include <iostream>
using namespace std;

class BT;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
        TreeNode():val(0), left(nullptr), right(nullptr) {};
        TreeNode(int x): val(x),left(nullptr),right(nullptr) {};
        TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode): val(x),left(leftNode),right(rightNode){};
    friend class BT;
};

class BT{
    public:
        TreeNode *root;
        BT():root(nullptr) {};
        BT(TreeNode *node):root(node){};

        //member functions
};


class BSTIterator {
public:
    TreeNode *current = new TreeNode;
    BSTIterator(TreeNode* root){
        root->val = -1;
        current = root;
    }
    
    TreeNode* leftmost(TreeNode* current){
        while(current->left!=NULL){
            current = current->left;
        }
        return current;
    }

    int next() {
        
        if(current->val == -1) return leftmost(current)->val;
        
        //Update to next pointer
        if(current->right!=NULL){ 
            current = leftmost(current->right);
            return current->val;
        }
      

    }
    
    bool hasNext() {
        if(current->right!=NULL){
            return true;
        }
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


int main(){

    // Construct a BST 1
    TreeNode *nodeA = new TreeNode(7);
    TreeNode *nodeB = new TreeNode(3);
    TreeNode *nodeC = new TreeNode(15);
    TreeNode *nodeD = new TreeNode(9);
    TreeNode *nodeE = new TreeNode(20);

    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeC->left = nodeD;
    nodeC->right = nodeE;

    BT T(nodeA);


    // Test Iterator    
    cout << "Should return the leftmost node" << endl;
        BSTIterator it(T.root);

    cout << it.next() << endl;
    cout << it.next() << endl;
    cout << it.hasNext() << endl;  
    
    //cout << it.leftmost(T.root)->val;
    

    return 0;
}