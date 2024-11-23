#include "AVLTree.h"

// Constructor to initialize an empty AVL tree with root set to nullptr
AVLTree::AVLTree() : root(nullptr) {}

// Function to get the height of a node
int AVLTree::getHeight(AVLNode* node) {
    return node ? node->height : 0; // Return height if node exists, otherwise return 0
}

// Function to get the balance factor of a node
int AVLTree::getBalanceFactor(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0; // Balance factor is height difference between left and right subtrees
}

// Function to perform a right rotation
AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;   // Set x to be the left child of y
    AVLNode* T = x->right;  // Set T to be the right child of x

    x->right = y;           // Perform rotation
    y->left = T;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1; // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // Return the new root
}

// Function to perform a left rotation
AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;  // Set y to be the right child of x
    AVLNode* T = y->left;   // Set T to be the left child of y

    y->left = x;            // Perform rotation
    x->right = T;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1; // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // Return the new root
}

// Helper function to insert a value into the AVL tree
AVLNode* AVLTree::insert(AVLNode* node, int value) {
    if (!node) return new AVLNode(value); // Create a new node if the tree is empty

    if (value < node->data) {
        node->left = insert(node->left, value); // Insert in the left subtree if value is less than node's data
    } else if (value > node->data) {
        node->right = insert(node->right, value); // Insert in the right subtree if value is greater than node's data
    } else {
        return node; // Duplicates not allowed
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right)); // Update the height of the ancestor node
    int balance = getBalanceFactor(node); // Get the balance factor of the ancestor node

    // Left Left Case
    if (balance > 1 && value < node->left->data) {
        return rotateRight(node);
    }
    // Right Right Case
    if (balance < -1 && value > node->right->data) {
        return rotateLeft(node);
    }
    // Left Right Case
    if (balance > 1 && value > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // Right Left Case
    if (balance < -1 && value < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node; // Return the (possibly unchanged) node pointer
}

// Helper function to remove a value from the AVL tree
AVLNode* AVLTree::remove(AVLNode* node, int value) {
    if (!node) return nullptr; // Base case: if the node is null, return null

    if (value < node->data) {
        node->left = remove(node->left, value); // Recur on the left subtree if value is less than node's data
    } else if (value > node->data) {
        node->right = remove(node->right, value); // Recur on the right subtree if value is greater than node's data
    } else {
        // Node with the value found; handle deletion
        if (!node->left || !node->right) {
            AVLNode* temp = node->left ? node->left : node->right;
            delete node; // Free memory
            return temp; // Return the non-null child or null if both are null
        }

        // Node has two children; find the inorder successor (smallest in the right subtree)
        AVLNode* temp = findMin(node->right);
        node->data = temp->data; // Copy the inorder successor's data to this node
        node->right = remove(node->right, temp->data); // Remove the inorder successor
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right)); // Update the height of the ancestor node
    int balance = getBalanceFactor(node); // Get the balance factor of the ancestor node

    // Left Left Case
    if (balance > 1 && getBalanceFactor(node->left) >= 0) {
        return rotateRight(node);
    }
    // Left Right Case
    if (balance > 1 && getBalanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // Right Right Case
    if (balance < -1 && getBalanceFactor(node->right) <= 0) {
        return rotateLeft(node);
    }
    // Right Left Case
    if (balance < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node; // Return the (possibly unchanged) node pointer
}

// Function to find the node with the minimum value in a subtree
AVLNode* AVLTree::findMin(AVLNode* node) {
    while (node && node->left) {
        node = node->left; // Move to the leftmost node
    }
    return node; // Return the leftmost node
}

// Public function to insert a value into the AVL tree
void AVLTree::insert(int value) {
    root = insert(root, value); // Call the helper function with the root node
}

// Public function to remove a value from the AVL tree
void AVLTree::remove(int value) {
    root = remove(root, value); // Call the helper function with the root node
}

// Public function to perform in-order traversal and print the tree
void AVLTree::inOrderTraversal() {
    inOrder(root); // Call the helper function with the root node
    cout << endl; // Print a newline after traversal
}

// Helper function for in-order traversal (left, root, right)
void AVLTree::inOrder(AVLNode* node) {
    if (node) {
        inOrder(node->left); // Traverse the left subtree
        cout << node->data << " "; // Visit the root node
        inOrder(node->right); // Traverse the right subtree
    }
}
