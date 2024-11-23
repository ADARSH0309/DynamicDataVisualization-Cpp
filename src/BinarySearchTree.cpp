#include "BinarySearchTree.h"

// Constructor to initialize an empty Binary Search Tree with root set to nullptr
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// Helper function to insert a value into the binary search tree
TreeNode* BinarySearchTree::insert(TreeNode* node, int value) {
    if (!node) return new TreeNode(value); // Create a new node if the tree is empty

    if (value < node->data) {
        node->left = insert(node->left, value); // Insert in the left subtree if value is less than node's data
    } else if (value > node->data) {
        node->right = insert(node->right, value); // Insert in the right subtree if value is greater than node's data
    }
    return node; // Return the (possibly unchanged) node pointer
}

// Helper function to remove a value from the binary search tree
TreeNode* BinarySearchTree::remove(TreeNode* node, int value) {
    if (!node) return nullptr; // Base case: if the node is null, return null

    if (value < node->data) {
        node->left = remove(node->left, value); // Recur on the left subtree if value is less than node's data
    } else if (value > node->data) {
        node->right = remove(node->right, value); // Recur on the right subtree if value is greater than node's data
    } else {
        // Node with the value found; handle deletion
        if (!node->left) {
            TreeNode* temp = node->right; // Node has no left child
            delete node; // Free memory
            return temp; // Return the right child to be linked to the parent node
        } else if (!node->right) {
            TreeNode* temp = node->left; // Node has no right child
            delete node; // Free memory
            return temp; // Return the left child to be linked to the parent node
        }

        // Node has two children; find the inorder successor (smallest in the right subtree)
        TreeNode* temp = findMin(node->right);
        node->data = temp->data; // Copy the inorder successor's data to this node
        node->right = remove(node->right, temp->data); // Remove the inorder successor
    }
    return node; // Return the (possibly unchanged) node pointer
}

// Helper function to find the minimum value node in a subtree
TreeNode* BinarySearchTree::findMin(TreeNode* node) {
    while (node && node->left) {
        node = node->left; // Move to the leftmost node
    }
    return node; // Return the leftmost node
}

// Public function to insert a value into the binary search tree
void BinarySearchTree::insert(int value) {
    root = insert(root, value); // Call the helper function with the root node
}

// Public function to remove a value from the binary search tree
void BinarySearchTree::remove(int value) {
    root = remove(root, value); // Call the helper function with the root node
}

// Public function to perform in-order traversal and print the tree
void BinarySearchTree::inOrderTraversal() {
    inOrder(root); // Call the helper function with the root node
    cout << endl; // Print a newline after traversal
}

// Public function to perform pre-order traversal and print the tree
void BinarySearchTree::preOrderTraversal() {
    preOrder(root); // Call the helper function with the root node
    cout << endl; // Print a newline after traversal
}

// Public function to perform post-order traversal and print the tree
void BinarySearchTree::postOrderTraversal() {
    postOrder(root); // Call the helper function with the root node
    cout << endl; // Print a newline after traversal
}

// Helper function for in-order traversal (left, root, right)
void BinarySearchTree::inOrder(TreeNode* node) {
    if (node) {
        inOrder(node->left); // Traverse the left subtree
        cout << node->data << " "; // Visit the root node
        inOrder(node->right); // Traverse the right subtree
    }
}

// Helper function for pre-order traversal (root, left, right)
void BinarySearchTree::preOrder(TreeNode* node) {
    if (node) {
        cout << node->data << " "; // Visit the root node
        preOrder(node->left); // Traverse the left subtree
        preOrder(node->right); // Traverse the right subtree
    }
}

// Helper function for post-order traversal (left, right, root)
void BinarySearchTree::postOrder(TreeNode* node) {
    if (node) {
        postOrder(node->left); // Traverse the left subtree
        postOrder(node->right); // Traverse the right subtree
        cout << node->data << " "; // Visit the root node
    }
}
