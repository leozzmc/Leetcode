# include <iostream>
# include <vector>
# include <queue>
using namespace std;

class BT;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(): val(0),left(nullptr),right(nullptr) {};
        TreeNode(int x): val(x),left(nullptr),right(nullptr) {};
        TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode): val(0),left(leftNode),right(rightNode) {};
    friend class BT;
};

class BT{
    public:
        TreeNode *root;

        BT():root(nullptr){};
        BT(TreeNode *node):root(node) {};

        //member functions
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
        TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd);
        void bfs(TreeNode* current);
};

TreeNode* BT::buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd){
    if(inStart> inEnd || postStart > postEnd) return nullptr;
    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);

    // divided into subArrays
    int mid;
    for(mid= inStart; mid <=inEnd; mid++){
        if(inorder[mid]==rootVal){
            break;
        }
    }
    
    int leftTreeSize = mid - inStart;

    root -> left = buildTreeHelper(inorder, postorder,inStart, mid-1, postStart, postStart+leftTreeSize-1 );
    root -> right = buildTreeHelper(inorder, postorder, mid+1, inEnd,postStart+leftTreeSize, postEnd-1);
    return root;
}


TreeNode* BT::buildTree(vector<int>& inorder, vector<int>& postorder){
    if(inorder.size()==0 || postorder.size()==0) return nullptr;
    return buildTreeHelper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
}

void BT::bfs(TreeNode *root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *current = q.front();
        cout << current->val << " ";
        q.pop();
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }

}

int main(){

    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    BT T;

    T.bfs(T.buildTree(inorder, postorder));
    

    return 0;
}