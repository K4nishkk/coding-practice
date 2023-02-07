// Binary search tree with inorder traversal
#include <iostream>
using namespace std;

class Node{
public:
    int data; // to store data
    Node* left, *right; // pointers to children nodes
    
    // constructor
    explicit Node(int d)
        : data{d}, left{nullptr}, right{nullptr} {}
};

class BST{
public:
    Node* root; // pointer to the root node
    
    // constructor
    BST ()
        : root{nullptr} {}
        
    // function to insert node
    void insertNode(int d) {
        if (root == nullptr)
            root = new Node(d);
        else {
            Node* focusNode{root};
            Node* parent;
            while(true) {
                parent = focusNode;
                if (d < focusNode -> data) {
                    focusNode = focusNode -> left;
                    if (focusNode == nullptr) {
                        parent -> left = new Node(d);
                        return;
                    }
                }
                else {
                    focusNode = focusNode -> right;
                    if (focusNode == nullptr) {
                        parent -> right = new Node(d);
                        return;
                    }
                }
            }
        }
    }
    
    // function for inorder traversal
    void printInorder(Node* focusNode) {
        if (focusNode == nullptr) 
            return;
        
        printInorder(focusNode -> left);
        cout << focusNode -> data << "   ";
        printInorder(focusNode -> right);
    }
    
    // function for preorder traversal
    void printPreorder(Node* focusNode) {
        if (focusNode == nullptr)
            return;
            
        cout << focusNode -> data << "   ";
        printPreorder(focusNode -> left);
        printPreorder(focusNode -> right);
    }
    
    // function for post order traversal
    void printPostorder(Node* focusNode) {
        if (focusNode == nullptr)
            return;
            
        printPostorder(focusNode -> left);
        printPostorder(focusNode -> right);
        cout << focusNode -> data << "   ";
    }
};

int main () {
    BST tree; 
    // don't use brackets for constructors with no parameters
    // compiler thinks it's a function
    // empty brackets are allowed in new declarations but not here
    
    // inserting nodes
    tree.insertNode(5);
    tree.insertNode(1);
    tree.insertNode(3);
    tree.insertNode(2);
    tree.insertNode(9);
    tree.insertNode(7);
    tree.insertNode(4);
    tree.insertNode(6);
    tree.insertNode(8);
    tree.insertNode(10);
        
    // tree traversal
    cout << "Inorder traversal: ";
    tree.printInorder(tree.root);
    
    cout << "\nPreorder traversal: ";
    tree.printPreorder(tree.root);
    
    cout << "\nPostorder traversal: ";
    tree.printPostorder(tree.root);
}
