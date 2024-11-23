#ifndef AVLTREE_H  // Header guard to prevent multiple inclusions of the same header file
#define AVLTREE_H

#include <iostream>  // For input/output operations
using namespace std; // Use the standard namespace to avoid prefixing standard library names

// Structure representing a node in the AVL tree
struct AVLNode {
    int data;             // Value stored in the node
    AVLNode* left;        // Pointer to the left child
    AVLNode* right;       // Pointer to the right child
    int height;           // Height of the node

    // Constructor to initialize a node with a given value
    AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

// Class representing an AVL tree
class AVLTree {
private:
    AVLNode* root;        // Pointer to the root of the tree

    // Function to get the height of a node
    int getHeight(AVLNode* node);

    // Function to get the balance factor of a node
    int getBalanceFactor(AVLNode* node);

    // Function to perform a right rotation
    AVLNode* rotateRight(AVLNode* y);

    // Function to perform a left rotation
    AVLNode* rotateLeft(AVLNode* x);

    // Helper function to insert a value into the AVL tree
    AVLNode* insert(AVLNode* node, int value);

    // Helper function to remove a value from the AVL tree
    AVLNode* remove(AVLNode* node, int value);

    // Function to find the node with the minimum value
    AVLNode* findMin(AVLNode* node);

    // Helper function for in-order traversal
    void inOrder(AVLNode* node);

public:
    // Constructor to initialize an empty AVL tree
    AVLTree();

    // Public function to insert a value into the AVL tree
    void insert(int value);

    // Public function to remove a value from the AVL tree
    void remove(int value);

    // Public function to perform in-order traversal and print the tree
    void inOrderTraversal();
};

#endif // End of header guard
