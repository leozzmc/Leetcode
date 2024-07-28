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


        // add 6 new member functions
        TreeNode * Leftmost(TreeNode *current);
        TreeNode * Rightmost(TreeNode *current);
        TreeNode * InorderSuccessor(TreeNode *current);
        TreeNode * InorderPredecessor(TreeNode *current);
        void Inorder_by_parent(TreeNode *root);
        void Inorder_Reverse(TreeNode *root);
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

TreeNode * BinaryTree::Leftmost(TreeNode *current){
    while(current->leftchild != NULL){
        current = current->leftchild;
    }
    return current;
}

TreeNode * BinaryTree::Rightmost(TreeNode *current){
    while(current->rightchild != NULL){
        current = current->rightchild;
    }
    return current;
}

TreeNode * BinaryTree::InorderSuccessor(TreeNode *current){
    if(current->rightchild != NULL){
        return Leftmost(current->rightchild);
    }
    TreeNode *Successor = current->parent;
    // if current node is succesor's right child, then keep moving back to it's parent node.
    while( Successor != NULL && current == Successor->rightchild){
        current = Successor;
        Successor = Successor->parent;
    }
    // Suceessor == NULL or the current node is Successor's left child
    return Successor;
}

TreeNode * BinaryTree::InorderPredecessor(TreeNode *current){
    if(current->leftchild != NULL){
        return Rightmost(current->leftchild);
    }

    TreeNode *Predecessor = current->parent;
    // if current node is not predecessor's right child, then keep moving back to it's parent node.
    while(Predecessor != NULL && current == Predecessor->leftchild){
        current = Predecessor;
        Predecessor = Predecessor->parent;
    }
    // Predecesor == NULL or current node is predecessor's right child.
    return Predecessor;

}


// Construct by the Leftmost() and InorderSuccessor() function
void BinaryTree::Inorder_by_parent(TreeNode *root){
    TreeNode *current = new TreeNode;
    current = Leftmost(root);

    while(current){
        cout << current->str << " ";
        current = InorderSuccessor(current);
    }
}

void BinaryTree::Inorder_Reverse(TreeNode *root){
    TreeNode *current = new TreeNode;
    current = Rightmost(root);

    while(current){
        cout << current->str << " ";
        current = InorderPredecessor(current);
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


    // Link the parent pointers
    nodeB -> parent = nodeA;
    nodeC -> parent = nodeA;
    nodeD -> parent = nodeB;
    nodeE -> parent = nodeB;
    nodeG -> parent = nodeE;
    nodeH -> parent = nodeE;
    nodeF -> parent = nodeC;
    nodeI ->parent = nodeF;


    //Traversal
    T.Preorder(T.root);
    cout << endl;
    T.Inorder(T.root);
    cout << endl;
    T.Postorder(T.root);
    cout << endl;
    T.Levelorder();
    cout << endl;

    // Inorder by Parent
    cout << "Inorder Traversal by Parent" << endl;
    T.Inorder_by_parent(T.root);
    cout << endl;
    cout << "Reverse Inorder Traversal by Parent" << endl;
    T.Inorder_Reverse(T.root);


    

    return 0;
}