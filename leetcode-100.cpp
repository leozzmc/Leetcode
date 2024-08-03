# include <iostream>

using namespace std;

class BT;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;

        TreeNode():val(0), left(0), right(0) {};
        TreeNode(int x):val(x), left(0), right(0) {};
        TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode):val(x), left(leftNode), right(rightNode) {};

        friend class BT;
};

class BT{
    public:
        TreeNode *root = new TreeNode;
        bool result =true;
        

        //constructor
        BT():root(0) {};
        BT(TreeNode *node): root(node) {};

        //member function
        bool isSameTree(TreeNode* p, TreeNode* q);

};

bool BT::isSameTree(TreeNode* p, TreeNode* q){
    
    if(p == NULL && q == NULL) return true;
    if (p == NULL && q != NULL) return false;
    if (p != NULL && q == NULL) return false;
    cout << "P:" << p->val << "q:" << q->val << endl;
    if(p->val != q->val ) {
        cout << "Not the same Tree" << endl;
        return  false;
    }
    if(p->left != NULL || q->left != NULL) result = isSameTree(p->left, q->left);
    if(p->right != NULL || q->right != NULL) result = isSameTree(p->right, q->right);
    return result;
}



int main(){

    //Tree 1
    // TreeNode *nodeA_1 = new TreeNode(1); 
    // TreeNode *nodeB_1= new TreeNode(2); 
    // TreeNode *nodeC_1 = new TreeNode(3); 

    // nodeA_1 -> left = nodeB_1;
    // nodeA_1 -> right = nodeC_1;

    // BT T1(nodeA_1);

    // TreeNode *nodeA_1 = new TreeNode(1); 
    // TreeNode *nodeB_1= new TreeNode(2); 

    // nodeA_1 -> left = nodeB_1;

    // BT T1(nodeA_1);

    TreeNode *nodeA_1 = new TreeNode(0); 
    TreeNode *nodeB_1= new TreeNode(-5); 

    nodeA_1 -> left = nodeB_1;

    BT T1(nodeA_1);



    //Tree2
    // TreeNode *nodeA_2 = new TreeNode(1); 
    // TreeNode *nodeB_2= new TreeNode(2); 
    // TreeNode *nodeC_2 = new TreeNode(3); 

    // nodeA_2 -> left = nodeB_2;
    // nodeA_2 -> right = nodeC_2;

    // BT T2(nodeA_2);

    // TreeNode *nodeA_2 = new TreeNode(1); 
    // TreeNode *nodeB_2= new TreeNode(2); 

    // nodeA_2 -> right = nodeB_2;

    // BT T2(nodeA_2);

    TreeNode *nodeA_2 = new TreeNode(0); 
    TreeNode *nodeB_2= new TreeNode(-8); 

    nodeA_2 -> left = nodeB_2;
    BT T2(nodeA_2);


    cout << "After comparison:"  << endl;
    cout << "Same tree?" << T1.isSameTree(T1.root, T2.root) << endl; 


    return 0;
}