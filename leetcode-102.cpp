# include <iostream>
# include <queue>
# include <vector>

using namespace std;

class BT;
class TreeNode{
    public:
        int val;
        TreeNode *right, *left;
        TreeNode(): val(0), right(0), left(0) {};
        TreeNode(int x): val(x), right(0), left(0) {};
        TreeNode(int x, TreeNode *rightNode, TreeNode* leftNode): val(x), right(rightNode), left(leftNode) {};

        friend class TreeNode;
};

class BT{
    public:
        TreeNode *root = new TreeNode;
        vector<vector<int>> result={};
        //constructor
        BT(): root(0) {};
        BT(TreeNode * node): root(node) {};
        //member function
        vector<vector<int>> levelOrder(TreeNode* root);
};

vector<vector<int>> BT::levelOrder(TreeNode* root){
    if(root == NULL) return result;
    queue<TreeNode*>q;
    int count = 0;
    q.push(root);
    while(!q.empty()){
        int levelSize = q.size();
        ++count;
        vector<int> currentLevel;  

        //cout << "Level " << ++count << endl;
        for(int i = 0; i < levelSize; ++i){
            TreeNode *current = q.front();
            q.pop();
            currentLevel.push_back(current->val); 

            if(current->left!=NULL){ 
                q.push(current->left);
                
            }
            if(current->right!=NULL){
                q.push(current->right);
            }

        }
        result.push_back(currentLevel);
    }
    return result;
}

int main(){

    vector<vector<int>> LV;

    TreeNode *nodeA = new TreeNode(1);
    TreeNode *nodeB = new TreeNode(2);
    TreeNode *nodeC = new TreeNode(3);
    TreeNode *nodeD = new TreeNode(4);
    TreeNode *nodeE = new TreeNode(5);

    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->left = nodeD;
    nodeC->right = nodeE;

    BT T(nodeA);

    cout << "Level Order" << endl;
    // T.levelOrder(T.root);
    LV = T.levelOrder(T.root);
    for (const auto& row : LV) {      // 對於每一行
        for (const auto& element : row) { // 對於行中的每一個元素
            std::cout << element << " ";
        }
        std::cout << std::endl;           // 換行以列印下一行
    }
    

    return 0;
}
