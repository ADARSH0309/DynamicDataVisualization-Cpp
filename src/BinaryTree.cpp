#include "BinaryTree.h"

// Constructor to initialize an empty binary tree with root set to nullptr
BinaryTree::BinaryTree() : root(nullptr) {}

// Function to insert a value into the binary tree
void BinaryTree::insert(int value) {
    Node* newNode = new Node(value);  // Create a new node with the given value
    if (!root) {                      // If the tree is empty, set the new node as the root
        root = newNode;
        return;
    }

    Node* current = root;             // Start from the root node
    while (true) {                    // Loop to find the correct position to insert the new node
        if (value < current->data) {  // If the value is less than the current node's data
            if (!current->left) {     // If there's no left child, insert here
                current->left = newNode;
                break;
            }
            current = current->left;  // Move to the left child
        } else {                      // If the value is greater or equal to the current node's data
            if (!current->right) {    // If there's no right child, insert here
                current->right = newNode;
                break;
            }
            current = current->right; // Move to the right child
        }
    }
}

// Helper function for in-order traversal (left, root, right)
void BinaryTree::inOrderTraversal(Node* node) {
    if (!node) return;                // Base case: if the node is null, return
    inOrderTraversal(node->left);     // Traverse the left subtree
    cout << node->data << " ";        // Visit the root node
    inOrderTraversal(node->right);    // Traverse the right subtree
}

// Public function to perform in-order traversal starting from the root
void BinaryTree::inOrder() {
    inOrderTraversal(root);
    cout << endl;
}

// Helper function for pre-order traversal (root, left, right)
void BinaryTree::preOrderTraversal(Node* node) {
    if (!node) return;                // Base case: if the node is null, return
    cout << node->data << " ";        // Visit the root node
    preOrderTraversal(node->left);    // Traverse the left subtree
    preOrderTraversal(node->right);   // Traverse the right subtree
}

// Public function to perform pre-order traversal starting from the root
void BinaryTree::preOrder() {
    preOrderTraversal(root);
    cout << endl;
}

// Helper function for post-order traversal (left, right, root)
void BinaryTree::postOrderTraversal(Node* node) {
    if (!node) return;                // Base case: if the node is null, return
    postOrderTraversal(node->left);   // Traverse the left subtree
    postOrderTraversal(node->right);  // Traverse the right subtree
    cout << node->data << " ";        // Visit the root node
}

// Public function to perform post-order traversal starting from the root
void BinaryTree::postOrder() {
    postOrderTraversal(root);
    cout << endl;
}
