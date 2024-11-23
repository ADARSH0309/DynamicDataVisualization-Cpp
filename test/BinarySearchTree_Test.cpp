#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

int main() {
    BinarySearchTree bst;

    // Test Insertion
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(7);

    cout << "In-Order Traversal after insertion: ";
    bst.inOrderTraversal(); // Expected: 5 7 10 15

    // Test Deletion
    bst.remove(5);
    cout << "In-Order Traversal after deleting 5: ";
    bst.inOrderTraversal(); // Expected: 7 10 15

    // Test Pre-Order and Post-Order Traversals
    cout << "Pre-Order Traversal: ";
    bst.preOrderTraversal(); // Expected: 10 7 15

    cout << "Post-Order Traversal: ";
    bst.postOrderTraversal(); // Expected: 7 15 10

    return 0;
}
