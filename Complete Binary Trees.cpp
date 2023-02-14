// Complete Binary Tree implementation
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cmath>
#include <queue>
using namespace std;

// function to get width for the terminal
int get_terminal_size(int width) {
    
    // needs the window.h header file
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    // calculating width and height and type-casting to int
    width = (int)(csbi.srWindow.Right - csbi.srWindow.Left + 1);
    return width;
}

class Node{
public:
    int data; // to store data
    Node* left, *right; // pointers to children node

    // constructor
    explicit Node(int d)
        : data{d}, left{nullptr}, right{nullptr} {}
};

class BinaryTree{
public:
    Node* root; // pointer to the root node

    // constructor
    BinaryTree()
        : root{nullptr} {}

    // function to insert node
    void insertNode(int d) {
        if (root == nullptr)
            root = new Node(d);

        else {
            queue<Node*> q; // creating a queue
            q.push(root); // pushing pointer to root node into the queue

            while (q.empty() == false) {
                Node* temp = q.front(); // creating a temporary pointer to node, queue's frontmost points to
                q.pop();

                if (temp -> left == nullptr) {
                    temp -> left = new Node(d);
                    return;
                }
                else
                    q.push(temp -> left);

                if (temp -> right == nullptr) {
                    temp -> right = new Node(d);
                    return;
                }
                else
                    q.push(temp -> right);
            }
        }
    }

    // function for inorder traversal of node
    void printInorder(Node* focusNode) {
        if (focusNode == nullptr)
            return;

        printInorder(focusNode -> left);
        cout << focusNode -> data << "   ";
        printInorder(focusNode -> right);
    }

    // function for preorder traversal of node
    void printPreorder(Node* focusNode) {
        if (focusNode == nullptr)
            return;

        cout << focusNode -> data << "   ";
        printPreorder(focusNode -> left);
        printPreorder(focusNode -> right);
    }

    // function for postorder traversal of node
    void printPostorder(Node* focusNode) {
        if (focusNode == nullptr)
            return;

        printPostorder(focusNode -> left);
        printPostorder(focusNode -> right);
        cout << focusNode -> data << "   ";
    }

    // function for level order traversal (Breadth - first)
    void printLevelorder(Node* focusNode) {
        if (focusNode == nullptr)
            return;

        else {
            queue<Node*> q; // creating a queue
            q.push(focusNode); // pushing root to queue

            while (q.empty() == false) {
                Node* temp = q.front();
                q.pop();

                if (temp == nullptr)
                    return;

                cout << temp -> data << "   ";

                q.push(temp -> left);
                q.push(temp -> right);
            }
        }
    }

    // function to print all the traversals
    void printTree(Node* focusNode) {
        cout << "\nInorder traversal: ";
        printInorder(focusNode);

        cout <<"\nPreorder traversal: ";
        printPreorder(focusNode);

        cout << "\nPostorder traversal: ";
        printPostorder(focusNode);

        cout << "\nLevelorder traversal: ";
        printLevelorder(focusNode);

        cout << endl;
    }

    // function to find the height of tree
    int height(Node* focusNode) {
        if (focusNode == nullptr)
            return 0;

        else {
            int lheight = height(focusNode -> left); // find height of left subtree
            int rheight = height(focusNode -> right); // find height of right subtree

            if (lheight > rheight)
                return lheight + 1;
            else 
                return rheight + 1;
        }
    }

    // function to delete last node (& return the value of that last node //***)
    int deleteLastNode(Node* focusNode) {
        if (focusNode == nullptr) // incase of 0 nodes
            return 0; //***

        if (focusNode -> left == nullptr && focusNode -> right == nullptr) { // incase of just root node
            int d = root -> data; //***
            root = nullptr;
            return d; //***
        }

        else { // level order traversal
            queue<Node*> q;
            q.push(focusNode);

            Node* prevNode{root};

            while (q.empty() == false) { 
                Node* temp = q.front();
                q.pop();

                if (temp -> left == nullptr) { // if left child is nullptr
                    int d = prevNode -> right -> data; //***
                    prevNode -> right = nullptr; // delete right child of previous node
                    return d; //***
                }
                if (temp -> right == nullptr) { // if right child is nullptr
                    int d = temp -> left -> data; //***
                    temp -> left = nullptr; // delete left child of same node
                    return d; //***
                }

                q.push(temp -> left);
                q.push(temp -> right);

                prevNode = temp;
            }
        }
        return 0;
    }

    // function to delete a node with data d
    // deletes last node and replaces the value of last node in node with data d
    void deleteNode(int d) {
        if (root == nullptr)
            return;

        if (root -> data == d) {
            root -> data = deleteLastNode(root);
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (q.empty() == false) {
            Node* temp = q.front();
            q.pop();

            if (temp == nullptr)
                return;

            if (temp -> data == d) {
                temp -> data = deleteLastNode(root);
                return;
            }

            q.push(temp -> left);
            q.push(temp -> right);
        }
    }

    // function to return pointer to the last node by reference
    Node** getLastNode() {
        if (root == nullptr)
            return nullptr;

        if (root -> left == nullptr && root -> right == nullptr)
            return &root;

        queue<Node*> q;
        q.push(root);

        Node* prevNode{root};

        while (q.empty() == false) {
            Node* temp = q.front();
            q.pop();

            if (temp -> left == nullptr)
                return &(prevNode -> right);
            if (temp -> right == nullptr)
                return &(prevNode -> left);

            q.push(temp -> left);
            q.push(temp -> right);

            prevNode = temp;
        }

        return nullptr;
    }
};

int main () {
    BinaryTree tree;
    
    // inserting 10, 20, 30.... 100
    for (int i{1}; i <= 10; i++)
        tree.insertNode(i * 10);

    tree.printTree(tree.root);

    cout << "\nheight: " << tree.height(tree.root) << endl;

    // deleting 3 nodes
    for (int i{}; i < 3; i++)
        tree.deleteLastNode(tree.root);

    tree.deleteNode(10);

    tree.printTree(tree.root);
}
