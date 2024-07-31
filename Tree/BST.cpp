#include <iostream>
#include <string>

using namespace std;

class BST;

class TreeNode{
    private:
        TreeNode *leftchild, *rightchild, *parent;
        int key;
        string element;
    public:
        //constructor
        TreeNode():leftchild(0),rightchild(0), parent(0), key(0), element("") {};
        TreeNode(int a, string b):leftchild(0),rightchild(0),parent(0), key(a), element(b){};

        // main() will use these functions to access pointers in the private section
        int GetKey() { return key;}
        string GetElement() { return element;}

    friend class BST; // Can access pointers in the private section in TreeNode class
};

class BST{
    private:
        TreeNode *root;
        TreeNode *leftmost(TreeNode *current);
        TreeNode* Successor(TreeNode *current);
    public:
        BST(): root(0){};

        TreeNode * search(int key);
        void insertBST(int key, string element);
        void inorderPrint();
        void levelorder();
        void DeleteBST(int key);
    friend class BST;
};

TreeNode *BST::search(int KEY){
    TreeNode *current = root;
    while(current!= NULL && KEY != current->key){
        if (current->key > KEY){
            current = current->leftchild;
        }
        else{
            current = current->rightchild;
        }
    }
    return current;
}

void BST::insertBST(int key, string element){
    TreeNode *current = root;
    TreeNode *parentInsert = NULL;
    TreeNode *insertNode = new TreeNode(key, element);


    //Find the appropriate insert position
    while(current != NULL){
        parentInsert = current;
        if(current-> key > insertNode->key){
            current = current->leftchild;
        }
        else{
            current = current->rightchild;
        }
    }

    insertNode->parent = parentInsert;

    if(parentInsert == NULL){
        this->root = insertNode;
    }
    else if(insertNode->key < parentInsert->key){
        parentInsert->leftchild = insertNode;
    }
    else if (insertNode->key > parentInsert->key){
        parentInsert->rightchild = insertNode;
    }
}

TreeNode *BST::leftmost(TreeNode *current){
    while(current->leftchild != NULL){
        current = current->leftchild;
    }
    return current;
};

TreeNode *BST::Successor(TreeNode *current){
    if(current->rightchild != NULL){
        return leftmost(current->rightchild);
    }
    TreeNode *SuccessorNode = current->parent;
    // if current node is succesor's right child, then keep moving back to it's parent node.
    while( SuccessorNode != NULL && current == SuccessorNode->rightchild){
        current = SuccessorNode;
        SuccessorNode = SuccessorNode->parent;
    }
    // Suceessor == NULL or the current node is Successor's left child
    return SuccessorNode;
}

// L -> V -> R
// Construct by the Leftmost() and InorderSuccessor() function
void BST::inorderPrint(){
    TreeNode *current = new TreeNode;
    current = leftmost(root);

    while(current){
        cout << current->element << "(" << current->key << ")" << " ";
        current = Successor(current);
    }
}

void BST::DeleteBST(int KEY){

    TreeNode *deleteNode = search(KEY);
    if(deleteNode == NULL){
        cout << "Error: no such node in the tree" << endl;
        return;
    }

    TreeNode *actualDeleteNode = 0;
    TreeNode *childOfDeleteNode = 0;

    if(deleteNode->leftchild == NULL || deleteNode->leftchild == NULL){
        // Case 1 or Case2
        actualDeleteNode = deleteNode;
    }
    else{ //Case3
        actualDeleteNode = Successor(deleteNode);
    }

    //Assign the child of the delete node to `childOfDeleteNode`
    if(actualDeleteNode->leftchild!=NULL){
        childOfDeleteNode = actualDeleteNode->leftchild;
    }
    else{
        childOfDeleteNode = actualDeleteNode->rightchild;
    }

    if(childOfDeleteNode!=NULL){ //Case2 or Case3
        childOfDeleteNode->parent = actualDeleteNode->parent;
    }

    //Parent point to the remain child
    if(actualDeleteNode->parent==NULL){ // if root node is deleted
        this->root = childOfDeleteNode;
    }
    else if(actualDeleteNode == actualDeleteNode->parent->leftchild){
         actualDeleteNode->parent->leftchild = childOfDeleteNode;
    }
    else{
        actualDeleteNode->parent->rightchild = childOfDeleteNode;
    }

    //Case3, the actualDeleteNode might be assigned to successor or predecessor
    if(deleteNode!= actualDeleteNode){
        deleteNode->key = actualDeleteNode->key;
        deleteNode->element = actualDeleteNode->element;
    }

    delete actualDeleteNode;
    actualDeleteNode = 0;
}

int main(){

    BST T;

    T.insertBST(500,"甚爾");
    T.insertBST(550,"羂索");
    T.insertBST(2500,"五條");
    T.insertBST(48,"七海");
    T.insertBST(1250,"乙骨");
    T.insertBST(13,"虎杖爺爺");
    T.insertBST(3000,"宿儺");
    T.insertBST(70,"東堂");
    T.insertBST(520,"里香");
    T.insertBST(50,"帳相");
    T.insertBST(12,"虎杖");


    cout << "Inorder Traversal:\n";
    T.inorderPrint();
    cout << endl;
    // cout << "Level-order Traversal:\n";
    // T.levelorder();
    // cout << endl << endl;
    T.DeleteBST(50);

    cout << "After deletion:\n";
    T.inorderPrint();
    cout << endl;

    TreeNode *node = T.search(1000);
    if(node != NULL){
        cout << "There is " << node->GetElement() << "(" << node->GetKey() << ")" << endl;
    }
    else {
        cout << "no element with Key(1000)" << endl;
    }

    node = T.search(73);
    if(node != NULL){
        cout << "There is " << node->GetElement() << "(" << node->GetKey() << ")" << endl;
    }
    else {
        cout << "no element with Key(73)" << endl;
    }

    return 0;
}