# include <iostream>
# include <vector>
# include <queue>

using namespace std;

class BT;
class TreeNode{
    public:
        double val;
        TreeNode *left, *right;
        TreeNode():val(0),left(nullptr),right(nullptr){};
        TreeNode(int x):val(x),left(nullptr),right(nullptr){};
        TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode):val(x),left(leftNode),right(rightNode){};
    friend class BT;
};

class BT{
    public:
        TreeNode *root = new TreeNode;
        BT(): root(nullptr){};
        BT(TreeNode *node): root(node){};

        //member function
        vector<double> averageOfLevels(TreeNode* root);
};

vector<double> BT::averageOfLevels(TreeNode* root){
    vector<double> result;
    queue<TreeNode*> q;
    double counter =0;
    
    q.push(root);

    //cout << q.front() << " ";
    while(!q.empty()){
        int levelSize = q.size();
        double avg=0;
        
    
        //cout << current->val << " ";
        for(int i = 0; i < levelSize; i++){
            TreeNode *current = q.front();
            q.pop();
            avg+=current->val;
            
            if(current->left != NULL){
                q.push(current->left);

            }
            if(current->right != NULL){
                q.push(current->right);
            }
        }
        result.push_back((double)(avg/(double)levelSize));
    }
    return result;
}

int main(){
    vector<double> result_vector;

    // // Test Tree1
    // TreeNode *nodeA = new TreeNode(3);
    // TreeNode *nodeB = new TreeNode(9);
    // TreeNode *nodeC = new TreeNode(20);
    // TreeNode *nodeD = new TreeNode(15);
    // TreeNode *nodeE = new TreeNode(7);

    // nodeA->left = nodeB;
    // nodeA->right = nodeC;
    // nodeB->left = nodeD;
    // nodeB->right = nodeE;

    // BT T(nodeA);

    // // Test Tree2
    // TreeNode *nodeA = new TreeNode(3);
    // TreeNode *nodeB = new TreeNode(1);
    // TreeNode *nodeC = new TreeNode(5);
    // TreeNode *nodeD = new TreeNode(0);
    // TreeNode *nodeE = new TreeNode(2);
    // TreeNode *nodeF = new TreeNode(4);
    // TreeNode *nodeG = new TreeNode(6);

    // nodeA->left = nodeB;
    // nodeA->right = nodeC;
    // nodeB->left = nodeD;
    // nodeB->right = nodeE;
    // nodeC->left = nodeF;
    // nodeC->right = nodeG;
    
    // BT T(nodeA);
    
    //Tree 3
    TreeNode *nodeA = new TreeNode(2147483647);
    TreeNode *nodeB = new TreeNode(2147483647);
    TreeNode *nodeC = new TreeNode(2147483647);

    nodeA->left = nodeB;
    nodeA->right = nodeC;
    BT T(nodeA);

    cout << "After level-order traversal" << endl;
    result_vector = T.averageOfLevels(T.root);
    for(int i=0; i< result_vector.size(); i++){
        cout << result_vector[i] << " ";
    }

    return 0;
}