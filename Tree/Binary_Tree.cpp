# include <iostream>
# include <string>
# include <queue>
using namespace std;

class BinaryTree;

class TreeNode{
    public:
        TreeNode *leftchild;
        TreeNode *rightchild;
        TreeNode *parent;
        string str;

        //constructor
        TreeNode(): leftchild(0), rightchild(0),parent(0), str(""){};
        TreeNode(string s): leftchild(0), rightchild(0), parent(0), str(s){};

        friend class BinaryTree;
};


class BinaryTree{
    public:
        // the root is the starting node ot the tree
        TreeNode *root; 
        BinaryTree(): root(0){};
        BinaryTree(TreeNode *node): root(node){};

        void Preorder(TreeNode *current);
        void Inorder(TreeNode *current);
        void Postorder(TreeNode *current);
        void Levelorder();
};

// V-> L-> R
void BinaryTree::Preorder(TreeNode *current){
    if(current){
        // visiting the current node
        cout << current->str << " " ;
        // if leftchild exists, moving currentNode to the left child
        Preorder(current->leftchild);
        Preorder(current->rightchild);
    }
}

// L -> V -> R
void BinaryTree::Inorder(TreeNode *current){
    if(current){
        Inorder(current->leftchild);
        cout << current->str << " " ;
        Inorder(current->rightchild);
    }

}

// L -> R -> V
void BinaryTree::Postorder(TreeNode *current){
    if(current){
        Postorder(current->leftchild);
        Postorder(current->rightchild);
        cout << current->str << " " ;
    }
}

// Using Queue
void BinaryTree::Levelorder(){
    queue<TreeNode*> q;
    q.push(this->root);

    while(!q.empty()){
        TreeNode *current = q.front();
        q.pop();

        cout << current->str << " " ;
        if(current->leftchild != NULL){
            q.push(current->leftchild);
        }
        if(current->rightchild != NULL){
            q.push(current->rightchild);
        }
    }
}

int main(){
    // Instanitate  all tree nodes
    TreeNode *nodeA = new TreeNode("A");
    TreeNode *nodeB = new TreeNode("B");
    TreeNode *nodeC = new TreeNode("C");
    TreeNode *nodeD = new TreeNode("D");
    TreeNode *nodeE = new TreeNode("E");
    TreeNode *nodeF = new TreeNode("F");
    TreeNode *nodeG = new TreeNode("G");
    TreeNode *nodeH = new TreeNode("H");
    TreeNode *nodeI = new TreeNode("I");

    //Construct a binary tree
    nodeA -> leftchild = nodeB;
    nodeA -> rightchild = nodeC;
    nodeB -> leftchild = nodeD;
    nodeB -> rightchild = nodeE;
    nodeE -> leftchild = nodeG;
    nodeE -> rightchild = nodeH;
    nodeC -> leftchild = nodeF;
    nodeF -> rightchild = nodeI;

    // Given a root node
    BinaryTree T(nodeA);

    //Traversal
    T.Preorder(T.root);
    cout << endl;
    T.Inorder(T.root);
    cout << endl;
    T.Postorder(T.root);
    cout << endl;
    T.Levelorder();
    cout << endl;

    return 0;
}