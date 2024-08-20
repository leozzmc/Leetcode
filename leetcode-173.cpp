# include <iostream>
# include <queue>
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
    TreeNode *current = nullptr;
    queue <int> q;
    BSTIterator(TreeNode* root){
        inorderTraversal(root);
    }
    
    void inorderTraversal(TreeNode *current){
        if(current == NULL) return;
        inorderTraversal(current->left);
        q.push(current->val);
        inorderTraversal(current->right);
    }


    int next() {
        if(!q.empty()){
            int top = q.front();
            q.pop();
            return top;    
        }
    }
    
    bool hasNext(){
        if(!q.empty()) return true;
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
    if(it.hasNext()) cout << "true"<< endl;
    else cout << "false"<< endl;
    cout << it.next() << endl;
    if(it.hasNext()) cout << "true"<< endl;
    else cout << "false"<< endl;
    cout << it.next() << endl;
    if(it.hasNext()) cout << "true"<< endl;
    else cout << "false"<< endl;
    cout << it.next() << endl;
    if(it.hasNext()) cout << "true"<< endl;
    else cout << "false"<< endl;
    
    //cout << it.leftmost(T.root)->val;
    

    return 0;
}