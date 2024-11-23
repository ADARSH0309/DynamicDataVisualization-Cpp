#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

// Class representing a Binary Tree
class BinaryTree {
private:
    // Definition of a tree node
    struct Node {
        int data;            // Value stored in the node
        Node* left;          // Pointer to the left child
        Node* right;         // Pointer to the right child
        Node(int value) : data(value), left(nullptr), right(nullptr) {}  // Constructor to initialize a node
    };
    Node* root;              // Pointer to the root of the tree

    // Helper function for in-order traversal
    void inOrderTraversal(Node* node);
    // Helper function for pre-order traversal
    void preOrderTraversal(Node* node);
    // Helper function for post-order traversal
    void postOrderTraversal(Node* node);

public:
    BinaryTree();            // Constructor to initialize an empty tree
    void insert(int value);  // Function to insert a value into the tree
    void inOrder();          // Function to perform in-order traversal
    void preOrder();         // Function to perform pre-order traversal
    void postOrder();        // Function to perform post-order traversal
};

#endif  // BINARYTREE_H
