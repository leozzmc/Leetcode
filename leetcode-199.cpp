# include <iostream>
# include <vector>
# include <queue>

using namespace std;

class BT;
class TreeNode{
    public:
        int val;
        TreeNode *left, *right;

        TreeNode():val(),left(nullptr),right(nullptr) {};
        TreeNode(int x):val(x),left(nullptr),right(nullptr) {};
        TreeNode(int x, TreeNode *leftNode,TreeNode *rightNode):val(x),left(leftNode),right(rightNode) {};
    friend BT;
};

class BT{
    public:
        TreeNode *root = new TreeNode;
        vector<int> result = {};
        
        BT():root(nullptr){};
        BT(TreeNode *node):root(node){};

        //member function
        vector<int> rightSideView(TreeNode* root);
};

vector<int> BT::rightSideView(TreeNode* root){
    if(root==nullptr) return result;
    
    queue<TreeNode*> q;
    //push root
    q.push(root);



    while(!q.empty()){
        int levelsize = q.size();
        
        for(int i=0; i< levelsize ;i++){
            TreeNode *current = q.front();
            q.pop();
        
            if(i==0) result.push_back(current->val);
            if(current->right) q.push(current->right);
            if( current->left) q.push(current->left);
        }
        
        
    }
    return result;
}

int main(){

    //Define test tree-1
    TreeNode *nodeA = new TreeNode(1);
    TreeNode *nodeB = new TreeNode(2);
    TreeNode *nodeC = new TreeNode(3);
    TreeNode *nodeD = new TreeNode(5);
    TreeNode *nodeE = new TreeNode(4);

    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->right = nodeD;
    nodeC->right = nodeE;

    BT T(nodeA);
    
    // TreeNode *nodeA = new TreeNode(1);
    // TreeNode *nodeB = new TreeNode(2);
    // TreeNode *nodeC = new TreeNode(3);
    // TreeNode *nodeD = new TreeNode(4);
    // nodeA->left = nodeB;
    // nodeA->right = nodeC;
    // nodeB->left = nodeD;
    
    // BT T(nodeA);
    
    // Test
    T.rightSideView(T.root);
    // Iterate through the result vector
    for(auto it=T.result.begin(); it!=T.result.end();++it){
        cout << *it << " ";
    }
    cout << endl;
    

    return 0;
}