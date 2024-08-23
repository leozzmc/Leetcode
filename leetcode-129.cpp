# include <iostream>
# include <cmath>
# include <vector>

using namespace std;

class BT;
class TreeNode {
    public:
        int val;
        TreeNode *left, *right;
        TreeNode():val(0),left(nullptr), right(nullptr){};
        TreeNode(int x):val(x),left(nullptr), right(nullptr){};
        TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode):val(x),left(leftNode), right(rightNode){};
    friend class BT;
};

class BT{
    public:
        TreeNode *root;
        int sum=0;

        BT():root(nullptr){}
        BT(TreeNode *node):root(node){};

        //member functions
        void dfs(TreeNode *current, int pathsum);
        int sumNumbers(TreeNode* root);
        
        
};

void BT::dfs (TreeNode *current, int pathsum){
    if(current == nullptr) return;
    pathsum = current -> val + pathsum * 10;
    cout << pathsum << endl;
    if(current->left != nullptr){
        dfs(current -> left, pathsum);
        
    }
    if(current->right != nullptr){
        dfs(current -> right, pathsum);
    }
    if(current->left == nullptr && current->right == nullptr) sum += pathsum;
    pathsum = 0;
}

int BT::sumNumbers(TreeNode* current){
    if(current == nullptr) return 0;
    dfs(current, 0);
    return sum;
}

int main(){

    //Test Tree1
    // TreeNode *nodeA = new TreeNode(4);
    // TreeNode *nodeB = new TreeNode(9);
    // TreeNode *nodeC = new TreeNode(0);
    // TreeNode *nodeD = new TreeNode(5);
    // TreeNode *nodeE = new TreeNode(1);

    // nodeA -> left = nodeB;
    // nodeA -> right = nodeC;
    // nodeB -> left = nodeD;
    // nodeB -> right = nodeE;



    //Test Tree2
    TreeNode *nodeA = new TreeNode(1);
    TreeNode *nodeB = new TreeNode(2);
    TreeNode *nodeC = new TreeNode(3);

    nodeA -> left = nodeB;
    nodeA -> right = nodeC;

    BT T(nodeA);

    // Sum the all paths
    cout << "Sum of all paths: " << T.sumNumbers(T.root) << endl;

    


    return 0;
}