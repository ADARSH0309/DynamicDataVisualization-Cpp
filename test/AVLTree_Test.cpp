#include "AVLTree.h"
#include <iostream>

using namespace std;

int main() {
    AVLTree avl;

    // Test Insertion and Balancing
    avl.insert(30);
    avl.insert(20);
    avl.insert(10); // This should trigger a rotation

    cout << "In-Order Traversal after balancing: ";
    avl.inOrderTraversal(); // Expected: 10 20 30

    // Test Deletion
    avl.remove(10);
    cout << "In-Order Traversal after deleting 10: ";
    avl.inOrderTraversal(); // Expected: 20 30

    return 0;
}
