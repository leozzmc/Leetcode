# include <iostream>
# include <queue>

using namespace std;

class BT;
class TreeNode{
    public:
        int val;
        TreeNode *left, *right;

        TreeNode():val(0),left(0),right(0){};
        TreeNode(int x):val(x),left(0),right(0){};
        TreeNode(int x, TreeNode* leftnode, TreeNode* rightnode):val(x),left(leftnode),right(rightnode){};
        friend class BT;
}; 


class BT{
    public:
        TreeNode *root = new TreeNode;

        //constructor
        BT(): root(0) {};
        BT(TreeNode* node):root(node){};

        //member function
        TreeNode * invertTree(TreeNode* root);
        void levelOrder();
};



void BT::levelOrder(){ 
    queue<TreeNode*> q;
    q.push(this->root);

    while(!q.empty()){
        TreeNode *current = q.front();
        q.pop();

        cout << current->val << " ";
        if(current->left != NULL){
            q.push(current->left);
        }
        if(current->right != NULL){
            q.push(current->right);
        }
    }
}

TreeNode *BT::invertTree(TreeNode* root){
    TreeNode *tmp = 0;
    TreeNode *current = root;
    if (root == nullptr) {
            return nullptr;
    }
    invertTree(current->left);
    invertTree(current->right);
    
    
    tmp = current->left;
    current->left = current->right;
    current->right = tmp;
    tmp =0;
    
    return root;
}

int main(){


    TreeNode *nodeA =  new TreeNode(4);
    TreeNode *nodeB =  new TreeNode(2);
    TreeNode *nodeC =  new TreeNode(7);
    TreeNode *nodeD =  new TreeNode(1);
    TreeNode *nodeE =  new TreeNode(3);
    TreeNode *nodeF =  new TreeNode(6);
    TreeNode *nodeG =  new TreeNode(9);

    // TreeNode *nodeA =  new TreeNode(2);
    // TreeNode *nodeB =  new TreeNode(3);
    // TreeNode *nodeC =  new TreeNode(1);


    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->left = nodeD;
    nodeB->right = nodeE;
    nodeC->left = nodeF;
    nodeC->right = nodeG;

    // nodeA->right = nodeB;
    // nodeB->right = nodeC;
    // nodeB->left = NULL;


    BT T(nodeA);

    cout << "Level Order: " << endl;
    T.levelOrder();

    T.invertTree(T.root);
    cout << "\nAfter Inverstion:" << endl;
    T.levelOrder();




    return 0;
}