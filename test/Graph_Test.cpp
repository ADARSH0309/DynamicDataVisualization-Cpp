#include "Graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    // Test BFS Traversal
    cout << "BFS starting from node 0: ";
    g.BFS(0); // Expected: 0 1 2 3 4

    // Test DFS Traversal
    cout << "DFS starting from node 0: ";
    g.DFS(0); // Expected: 0 1 3 4 2

    return 0;
}
