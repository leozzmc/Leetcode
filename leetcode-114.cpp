#include <iostream>
using namespace std;


class BT;
class TreeNode {
    public:
        int val;
        TreeNode *left, *right;
        TreeNode():val(), left(nullptr), right(nullptr) {};
        TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
        TreeNode(int x, TreeNode* leftNode, TreeNode* rightNode): val(x), left(leftNode), right(rightNode) {};
    friend class BT;
};

class BT {
    public:
        TreeNode *root;
        BT(): root(nullptr) {};
        BT(TreeNode *node): root(node){};

        //member functions
        void preorder(TreeNode *current);
        void flatten(TreeNode* root);
};

void BT::preorder(TreeNode *current) {
    if(current == nullptr) return;
    cout << current->val << " ";
    preorder(current->left);
    preorder(current->right);

}



// void BT::flatten(TreeNode* root){
//     if(root == nullptr) return;
//     TreeNode *current = root;
//     TreeNode *ptr = nullptr;
//     if(current->right!= nullptr){
//         ptr = current -> right;
//         current -> right = nullptr;
//     }
//     current -> right = current -> left;
//     current -> left = nullptr;
//     //find the righmost node
//     while(current->right != nullptr){
//         current = current -> right;
//     }
//     current -> right = ptr;
//     current = root;
//     while(current->left){
//         current = current -> right;
//     }
//     flatten(current);  
// };

void BT::flatten(TreeNode* root){
    if(root == nullptr) return;
    TreeNode *current = root;
    TreeNode *ptr = nullptr;
    if(current->left!= nullptr){
        ptr = current -> right;
        current -> right = current -> left;
        current -> left = nullptr;

        while(current->right != nullptr){
            current = current -> right;
        }
        current -> right = ptr;
    }
    
    //find the righmost node

    flatten(root->right);  
};

int main() {
    
    TreeNode *nodeA = new TreeNode(1);
    TreeNode *nodeB = new TreeNode(2);
    TreeNode *nodeC = new TreeNode(3);
    TreeNode *nodeD = new TreeNode(4);
    TreeNode *nodeE = new TreeNode(5);
    TreeNode *nodeF = new TreeNode(6);

    nodeA ->left = nodeB;
    nodeA -> right = nodeE;
    nodeB -> left = nodeC;
    nodeB -> right = nodeD;
    nodeE -> right = nodeF;

    BT T(nodeA);

    //Test Traversals
    cout << "Preorder traversal: ";
    T.preorder(T.root);
    T.flatten(T.root);
 
    return 0;
}