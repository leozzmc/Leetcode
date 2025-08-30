#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==nullptr)return nullptr;
   
    if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
    else if(root-> val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
    else return root; // when root is q or p
  
}


void main(){

    TreeNode nodeA = TreeNode(6);
    TreeNode nodeB = TreeNode(2);
    TreeNode nodeC = TreeNode(8);
    TreeNode nodeD = TreeNode(0);
    TreeNode nodeE = TreeNode(4);
    TreeNode nodeF = TreeNode(7);
    TreeNode nodeG = TreeNode(9);
    TreeNode nodeH = TreeNode(3);
    TreeNode nodeI = TreeNode(5);

    nodeA.left = &nodeB;
    nodeA.right = &nodeC;
    nodeB.left = &nodeD;
    nodeB.right = &nodeE;
    nodeC.left = &nodeF;
    nodeC.right = &nodeG;
    nodeE.left = &nodeH;
    nodeE.right = &nodeI;
    TreeNode* resultNode = lowestCommonAncestor(&nodeA, &nodeB, &nodeC);
    cout << "The lowest common ancestor is: " << resultNode->val << endl;

}