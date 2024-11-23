#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main() {
    BinaryTree bt;

    // Test Insertion
    bt.insert(10);
    bt.insert(5);
    bt.insert(15);
    bt.insert(7);

    cout << "In-Order Traversal after insertion: ";
    bt.inOrderTraversal(); // Expected: 5 7 10 15

    // Test Pre-Order Traversal
    cout << "Pre-Order Traversal: ";
    bt.preOrderTraversal(); // Expected: 10 5 7 15

    // Test Post-Order Traversal
    cout << "Post-Order Traversal: ";
    bt.postOrderTraversal(); // Expected: 7 5 15 10

    // Test Deletion
    bt.remove(5);
    cout << "In-Order Traversal after deleting 5: ";
    bt.inOrderTraversal(); // Expected: 7 10 15

    return 0;
}
