// singly linked-list
#include <iostream>
using namespace std;

class Node{
public:
    int data; // to store data
    Node* next; // pointer to the next node

    // constructor
    explicit Node(int d = 0)
        : data{d}, next{nullptr} {}
};

// function to print linked list
void printList(Node* n) {
    cout << "Linked list: ";
    while (n != nullptr) {
        cout << n -> data << " -> ";
        n = n -> next;
    }
    cout << "NULL" << endl;
}

// function to find the size of linked list
int getSize(Node* n) {
    unsigned int count{};
    while (n != nullptr) {
        ++count;
        n = n -> next;
    }
    return count;
}

// function to insert node at last position
void insertLastNode(Node** n, int d) {
    if (*n == nullptr)
        *n = new Node(d);
    else {
        Node* ptr = *n; // ptr points to first node (same as head node)
        while (ptr -> next != nullptr)
            ptr = ptr -> next; // now ptr points to node with next as nullptr
        ptr -> next = new Node(d);
    }
}

// function to insert node at first position
void insertFirstNode(Node** n, int d) {
    if (*n == nullptr)
        *n = new Node(d);
    else {
        Node* ptr = new Node(d); // ptr points to new node
        ptr -> next = *n; // new node points to first node
        *n = ptr; // head points to new node
    }
}

// function to insert a node at position p
void insertNode(Node** n, int d, int p) {
    if (p == 1)
        insertFirstNode(n, d);

    else if (p == getSize(*n) + 1)
        insertLastNode(n, d);
        
    else if (p > 1 && p <= getSize(*n)) {
        Node* ptr = *n;

        for (int i{2}; i < p; i++) // ptr points to (p - 1)th node
            ptr = ptr -> next;

        Node* newPtr = new Node(d); // allocating new node in heap
        newPtr -> next = ptr -> next; // new node points to original node at pth position
        ptr -> next = newPtr; // (p - 1)th node points to new node
    }
    else 
        cout << p << " is not a valid position to insert node." << endl;
    
}

// function to deleter the last node
void deleteLastNode(Node** n) {
    if (*n == nullptr) // incase of empty linked list
        return;

    Node* ptr = *n;
    if (ptr -> next == nullptr) // incase of just 1 node
        *n = nullptr;

    else {
        while (ptr -> next -> next != nullptr) // traverse to the second last node
            ptr = ptr -> next;
        ptr -> next = nullptr; // second last node points to nullptr
    }
}

// function to delete first node
void deleteFirstNode(Node** n) {
    if (*n == nullptr)
        return;
    
    Node* ptr = *n;
    *n = ptr -> next;
}

// function to delete node at pth position
void deleteNode(Node** n, int p) {
    if (p == 1)
        deleteFirstNode(n);

    else if (p == getSize(*n))
        deleteLastNode(n);

    else if (p > 1 && p < getSize(*n)) {
        Node* ptr = *n;
        for (int i{2}; i < p; i++) // traverse to (p - 1)th node
            ptr = ptr -> next;
        ptr -> next = ptr -> next -> next; // pointing (p - 1)th node to (p + 1)th node
    }
    else 
        cout << p << " is not a valid position to insert node." << endl;
}

// function to delete a node with data d
void deleteKey(Node** n, int d) {
    if (*n == nullptr) // incase of empty list
        return;
    
    Node* prevPtr{*n}, *ptr{prevPtr -> next};

    if (prevPtr -> data == d) { // incase of first node deletion
        deleteFirstNode(n);
        return;
    }

    while (ptr -> data != d) { // in between or last node deletion
        prevPtr = ptr;
        ptr = ptr -> next;
        if (ptr == nullptr) {
            cout << "Node with key " << d << " doesn't exist" << endl;
            return;
        }
    }

    prevPtr -> next = ptr -> next;
}

// function to reverse the linked list
void reverseList(Node** n) {
    Node* ptr = *n;
    Node* prevPtr{nullptr}, *nextPtr{nullptr};

    while (ptr != nullptr) {
        nextPtr = ptr -> next;
        ptr -> next = prevPtr;
        prevPtr = ptr;
        ptr = nextPtr;
    }

    *n = prevPtr;
}

// QUICKSORT FUNCTION

Node* getTail(Node *n) {
    while (n && n -> next)
        n = n -> next;
    return n;
}

Node* partition(Node* head, Node* tail, Node** newHead, Node** newTail) {
    Node* pivot{tail};
    Node* prevPtr{nullptr}, *ptr{head}, *tailPtr{pivot};

    while (ptr != pivot) { // loop till the node just before the pivot
        if (ptr -> data < pivot -> data) {

            if (*newHead == nullptr)
                *newHead = ptr;

            prevPtr = ptr;
            ptr = ptr -> next;
        }
        else {
            if (prevPtr != nullptr)
                prevPtr -> next = ptr -> next;
            Node* nextPtr = ptr -> next;
            ptr -> next = nullptr;
            tailPtr -> next = ptr;
            tailPtr = ptr;
            ptr = nextPtr;
        }
    }

    if (*newHead == nullptr)
        *newHead = pivot;

    *newTail = tailPtr;

    return pivot;
}

Node* quickSortRecur(Node* head, Node* tail) {
    // base case
    if (head == nullptr || head == tail)
        return head;
    
    Node* newHead{nullptr}, *newTail{nullptr};

    Node* pivot{partition(head, tail, &newHead, &newTail)};

    // calling quickSort on left of the linked list
    if (newHead != pivot) {
        Node* ptr = newHead;
        while (ptr -> next != pivot)
            ptr = ptr -> next;
        ptr -> next = nullptr;

        newHead = quickSortRecur(newHead, ptr);

        ptr = getTail(newHead);
        ptr -> next = pivot;
    }

    // calling quicksort on right of the linked list
    pivot -> next = quickSortRecur(pivot -> next, newTail);

    return newHead;
}

void quickSort(Node** n) {
    *n = quickSortRecur(*n, getTail(*n));
}

// MERGE SORT ALGORITHM (approach 1)

Node* merge(Node* a, Node* b) {
    Node* result{nullptr};

    // base case
    if (a == nullptr)
        return b;
    else if (b == nullptr) 
        return a;

    if (a -> data <= b -> data) {
        result = a;
        result -> next = merge(a -> next, b);
    }
    else {
        result = b;
        result -> next = merge(a, b -> next);
    }

    return result;
}

void split(Node* n, Node** a, Node** b) {
    *a = n;

    // locate the middle node
    Node* n2{n -> next};
    while (n && n2 && n2 -> next) {
        n = n -> next;
        n2 = n2 -> next;
    } // now n is the middle node

    *b = n -> next;
    n -> next = nullptr;
}

void mergeSort(Node** n) {
    Node* head{*n};
    Node* a{nullptr}, *b{nullptr}; // linked lists to store split lists

    // base case
    if (head == nullptr || head -> next == nullptr)
        return;

    split(head, &a, &b); // split the lists

    mergeSort(&a); // merge sort individuals lists recursively
    mergeSort(&b);

    *n = merge(a, b);
}

// searching algorithm
bool searchList(Node* n, int d) {
    while (n != nullptr) {
        if (n -> data == d)
            return true;
        n = n -> next;
    }
    return false;
}

int main () {
    cout << endl;
    Node* head{nullptr};

    insertLastNode(&head, 10);
    insertLastNode(&head, 20);
    insertLastNode(&head, 30);
    insertLastNode(&head, 40);
    insertLastNode(&head, 50);
    insertLastNode(&head, 60);

    insertFirstNode(&head, 70);
    insertFirstNode(&head, 80);
    insertFirstNode(&head, 90);
    insertFirstNode(&head, 100);
    insertFirstNode(&head, 110);
    insertFirstNode(&head, 120);

    insertNode(&head, 130, 1);
    insertNode(&head, 140, 10);
    insertNode(&head, 150, 4);
    insertNode(&head, 160, 17);
    insertNode(&head, 170, -2);

    printList(head);

    deleteLastNode(&head);
    deleteLastNode(&head);

    deleteFirstNode(&head);
    deleteFirstNode(&head);

    printList(head);

    deleteNode(&head, 1);
    deleteNode(&head, 6);
    deleteNode(&head, 3);
    deleteNode(&head, 10);
    deleteNode(&head, -2);

    printList(head);

    deleteKey(&head, 150); // first node
    deleteKey(&head, 40); // last node
    deleteKey(&head, 70); // in between node
    deleteKey(&head, 500); // doesn't exist

    printList(head);

    // calling quickSort
    mergeSort(&head);

    cout << "Sorted ";
    printList(head);

    reverseList(&head);

    cout << "Reversed ";
    printList(head);

    cout << "Searching list for 100: " << (searchList(head, 100) ? "TRUE" : "FALSE") << endl;
    cout << "Searching list for 200: " << (searchList(head, 200) ? "TRUE" : "FALSE") << endl;

    cout << "Size of above linked list is: " << getSize(head) << endl;
    cout << endl;
}
