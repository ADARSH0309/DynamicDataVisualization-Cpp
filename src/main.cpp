#include "BinaryTree.h"
#include "AVLTree.h"
#include "Graph.h"

int main() {

   // Test Binary Tree
   BinaryTree bt;
   bt.insert(10);
   bt.insert(5);
   bt.insert(15);

   cout << "Binary Tree In-order: ";
   bt.inorderTraversal(); // Expected Output: 5 10 15

   // Test AVL Tree
   AVLTree avl;
   avl.insert(30); // Insertions should balance the tree.
   avl.insert(20);
   avl.insert(10);

   // Note: Implementing the display function for the AVL tree is needed for output.

   // Test Graph BFS Traversal
   Graph g;
   g.addEdge('A', 'B', 1);
   g.addEdge('A', 'C', 4);
   g.addEdge('B', 'C', 2);

   cout << "BFS Traversal starting from A: ";
   g.BFS('A'); // Expected Output: A B C

   auto shortestPath = g.Dijkstra('A', 'C');
   
   cout << "Shortest path from A to C: ";
   
   for (char c : shortestPath)
       cout << c << " "; // Expected Output: A B C

   return 0;
}
