# include <iostream>

using namespace std;

class BT;
class TreeNode{
    public:
        int val;
        
        TreeNode *left, *right;

        TreeNode():val(0), left(nullptr), right(nullptr) {};
        TreeNode(int x):val(x), left(nullptr), right(nullptr) {};
        TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode):val(x), left(leftNode), right(rightNode) {};
    friend class BT;
};

class BT{
    public:
        TreeNode *root  = new TreeNode;
        int TargetSum = 1;
        bool reachLeaf = false;;

        BT(): root(nullptr){};
        BT(TreeNode *node):root(node){};

        //member function
        bool inorder (TreeNode *current, int counter, int targetSum);
        bool hasPathSum(TreeNode* root, int targetSum);
};

bool BT::inorder (TreeNode *current, int counter, int targetSum){
 
    if (current == nullptr){
        return false;
    }
    counter += current->val;
    cout << current->val << endl;
    cout << "count: " << counter << endl;
    
    // compare the counter and targetSum while visiting the leaf node. 
    if(current->left == nullptr && current->right == nullptr){
        if(counter == targetSum){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    
    bool path1 = inorder(current->left, counter , targetSum);
    if( path1){
       return true;
    }

    
    bool path2 = inorder(current->right, counter , targetSum);
    if(path2){
       cout << counter;
       return true;
    }

    
    return false;
}

bool BT::hasPathSum(TreeNode* current, int targetSum){
    int count = 0;
    if(current == nullptr) return false;
    return inorder(current,count, targetSum);
}

int main(){

    // Test Tree 1 
    // TreeNode *nodeA = new TreeNode(5);
    // TreeNode *nodeB = new TreeNode(4);
    // TreeNode *nodeC = new TreeNode(8);
    // TreeNode *nodeD = new TreeNode(11);
    // TreeNode *nodeE = new TreeNode(13);
    // TreeNode *nodeF = new TreeNode(4);
    // TreeNode *nodeG = new TreeNode(7);
    // TreeNode *nodeH = new TreeNode(5);
    // TreeNode *nodeI = new TreeNode(1);

    // nodeA->left = nodeB;
    // nodeA->right = nodeC;
    // nodeB->left = nodeD;
    // nodeC->left = nodeE;
    // nodeC->right = nodeF;
    // nodeD->left = nodeG;
    // nodeD->right = nodeH;
    // nodeF->right = nodeI;

    // BT T(nodeA);
    
    //Test Tree 2 
    TreeNode *nodeA = new TreeNode(1);
    TreeNode *nodeB = new TreeNode(2);

    nodeA->left = nodeB;


    BT T(nodeA);
    
    
    cout << "has Path Sum?" << endl;
    if(T.hasPathSum(T.root, T.TargetSum)) cout << "\n Has path sum" << endl;
    else cout << "\n No path sum" << endl;

    return 0;
}