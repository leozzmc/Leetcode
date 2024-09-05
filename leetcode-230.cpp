# include <iostream>
using namespace std;


class BT;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
        TreeNode():val(0),left(nullptr),right(nullptr) {};
        TreeNode(int x):val(x),left(nullptr),right(nullptr) {};
        TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode):val(x),left(leftNode),right(rightNode) {};
    friend class BT;
};

class BT{
    public:
        TreeNode *root = new TreeNode;
        int count =0;
        int result;
        BT():root(nullptr){};
        BT(TreeNode *node):root(node){};

        //member functions
        void dfs(TreeNode *current, int k);
        int kthSmallest(TreeNode* root, int k);

};

void BT::dfs(TreeNode *current, int k){
    if(current==nullptr) return;
    dfs(current -> left, k);
    //node visiting
    count++;
    if(count==k) result=current->val;
    //cout << current ->val << " ";
    dfs(current -> right,k);

}
int BT::kthSmallest(TreeNode* root, int k){
    if(root==nullptr) return -1;
    dfs(root, k);
    return result;
}

int main(){
    
    //Test Tree1
    // TreeNode *nodeA = new TreeNode(3);
    // TreeNode *nodeB = new TreeNode(1);
    // TreeNode *nodeC = new TreeNode(4);
    // TreeNode *nodeD = new TreeNode(2);

    // nodeA ->left = nodeB;
    // nodeA -> right = nodeC;
    // nodeB ->right = nodeD;

    // BT T(nodeA);
    
    TreeNode *nodeA = new TreeNode(5);
    TreeNode *nodeB = new TreeNode(3);
    TreeNode *nodeC = new TreeNode(6);
    TreeNode *nodeD = new TreeNode(2);
    TreeNode *nodeE = new TreeNode(4);
    TreeNode *nodeF = new TreeNode(1);

    nodeA ->left = nodeB;
    nodeA -> right = nodeC;
    nodeB ->left = nodeD;
    nodeB -> right = nodeE;
    nodeD -> left = nodeF;

    BT T(nodeA);

    //output
    cout << "The Kth Smallest: " << T.kthSmallest(T.root, 3) << endl;
}