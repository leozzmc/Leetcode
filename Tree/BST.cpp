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
        TreeNode *rightmost(TreeNode *current);
    public:
        BST(): root(0){};

        TreeNode * search(int key);
        void insertBST(int key, string element);
        void inorderPrint(TreeNode *current);
        void inorderPrint();
        void levelorder();
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


// L -> V -> R
void BST::inorderPrint(TreeNode *current){

    if(current){
        inorderPrint(current->leftchild);
        cout << current->element << "(" << current->key << ")" << " " ;
        inorderPrint(current->rightchild);
    }
}

void BST::inorderPrint(){
    inorderPrint(root);
}




int main(){

    BST T;

    T.insertBST(500,"甚爾");
    T.insertBST(550,"羂索");
    T.insertBST(2500,"五條");
    T.insertBST(1250,"乙骨");
    T.insertBST(3000,"宿儺");
    T.insertBST(520,"里香");

    cout << "Inorder Traversal:\n";
    T.inorderPrint();
    cout << endl;
    // cout << "Level-order Traversal:\n";
    // T.levelorder();
    // cout << endl << endl;

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