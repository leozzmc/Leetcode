#include <iostream>
#include <vector>
using namespace std;

class BT;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* leftNode, TreeNode* rightNode) : val(x), left(leftNode), right(rightNode) {}
    friend class BT;
};

class BT {
public:
    TreeNode* root;
    vector<int> preorder_list;
    vector<int> inorder_list;

    BT() : root(nullptr) {}
    BT(TreeNode* node) : root(node) {}

    // member functions
    void preorder(TreeNode* current);
    void inorder(TreeNode* current);
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
    TreeNode* buildTreeHelper(const std::vector<int>& preorder, int preStart, int preEnd,
                              const std::vector<int>& inorder, int inStart, int inEnd);
};

TreeNode* BT::buildTreeHelper(const std::vector<int>& preorder, int preStart, int preEnd,
                              const std::vector<int>& inorder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    int mid;
    for (mid = inStart; mid <= inEnd; mid++) {
        if (inorder[mid] == rootVal) {
            break;
        }
    }

    int leftTreeSize = mid - inStart;

    root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftTreeSize, inorder, inStart, mid - 1);
    root->right = buildTreeHelper(preorder, preStart + leftTreeSize + 1, preEnd, inorder, mid + 1, inEnd);

    return root;
}

TreeNode* BT::buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) return nullptr;

    return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

void BT::preorder(TreeNode* current) {
    if (current == nullptr) return;
    cout << current->val << " ";
    preorder(current->left);
    preorder(current->right);
}
void BT::inorder(TreeNode* current) {
    if (current == nullptr) return;
    
    inorder(current->left);
    cout << current->val << " ";
    inorder(current->right);
}


int main() {
    BT T;

    vector<int> preorder_list = {3, 9, 20, 15, 7};
    vector<int> inorder_list = {9, 3, 15, 20, 7};
    T.root = T.buildTree(preorder_list, inorder_list);
    cout << "preorder:" << endl;
    T.preorder(T.root);
    cout << "inorder:" << endl; 
    T.inorder(T.root);
    return 0;
}
