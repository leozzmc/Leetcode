# include <iostream>
# include <vector>
using namespace std;

class BT;
class TreeNode{
    public:
        int val;
        TreeNode *right, *left;

        TreeNode(): val(0),right(0),left(0){};
        TreeNode(int x): val(x),right(0),left(0){};
        TreeNode(int x, TreeNode *rightNode, TreeNode *leftNode): val(x),right(rightNode),left(leftNode){};

        friend class BT;
};

class BT{
    public:
        TreeNode *root = new TreeNode;
        vector<int> result_inorder;
        vector<int> result_reverseorder;

        //constructor
        BT ():root(0){};
        BT (TreeNode *node):root(node){};

        //member function
        bool isSymmetric(TreeNode* node);
        bool isMirror(TreeNode* left, TreeNode* right);
        //void inorder(TreeNode* node);
};

// void BT::inorder(TreeNode* node){
//     if(node==NULL) return;
    
//     cout << node->val << " ";
//     result_inorder.push_back(node->val);
//     inorder(node->left);
//     inorder(node->right);
// };



// bool BT::isSymmetric(TreeNode* root){
//     bool result = false;
//     inorder(root);
//     //cout << endl;
//     for(int i=0; i<(int)(result_inorder.size()/2)+1;++i){
//         //cout <<  result_inorder[i] << " ";
//         if(result_inorder[i]!=result_inorder[result_inorder.size() -i -1]) return false;
//         else result = true;
//     }
//     return result;    
// }

bool BT::isMirror(TreeNode* leftNode, TreeNode* rightNode){
    if(leftNode == NULL && rightNode == NULL) return true;
        if(leftNode == NULL || rightNode == NULL) return false;
        
        if (leftNode->val == rightNode->val && 
            isMirror(leftNode->left, leftNode->right) && 
            isMirror(rightNode->left, rightNode->right)) return true;
        else return false;

}

bool BT::isSymmetric(TreeNode* root){
    bool result;
    result = isMirror(root->left, root->right);
    return result;    
}


int main(){

    //Test Tree1
    // TreeNode *nodeA = new TreeNode(1);
    // TreeNode *nodeB = new TreeNode(2);
    // TreeNode *nodeC = new TreeNode(2);
    // TreeNode *nodeD = new TreeNode(3);
    // TreeNode *nodeE = new TreeNode(4);
    // TreeNode *nodeF = new TreeNode(4);
    // TreeNode *nodeG = new TreeNode(3);

    // nodeA->left = nodeB;
    // nodeA->right = nodeC;
    // nodeB->left = nodeD;
    // nodeB->right = nodeE;
    // nodeC->left = nodeF;
    // nodeC->right = nodeG;

    // BT T(nodeA);

    //Test Tree2
    TreeNode *nodeA = new TreeNode(1);
    TreeNode *nodeB = new TreeNode(2);
    TreeNode *nodeC = new TreeNode(2);
    TreeNode *nodeD = new TreeNode(2);
    TreeNode *nodeE = new TreeNode(2);


    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->left = nodeD;
    nodeC->left = nodeE;

    BT T(nodeA);

    cout << "Inorder Traversal: " << endl; 
    cout << "\nIf the tree is symmetric? " << T.isSymmetric(T.root) << endl;


    return 0;    
}