#ifndef GRAPH_H  // Header guard to prevent multiple inclusions of the same header file
#define GRAPH_H

#include <iostream>       // Include for input/output operations
#include <vector>         // Include for using the vector container
#include <queue>          // Include for using the queue container
#include <unordered_map>  // Include for using the unordered_map container
#include <climits>        // Include for using INT_MAX
using namespace std;      // Use the standard namespace

// Class representing a graph
class Graph {
private:
    // Adjacency list representation of the graph
    // Each node maps to a vector of pairs (neighbor node, edge weight)
    unordered_map<char, vector<pair<char, int>>> adjList;

public:
    // Function to add an edge to the graph
    void addEdge(char u, char v, int weight);

    // Function to perform Breadth-First Search (BFS) on the graph
    void bfs(char start);

    // Function to perform Depth-First Search (DFS) on the graph
    void dfs(char start);

    // Function to perform Dijkstra's algorithm on the graph
    void dijkstra(char start);
};

#endif  // End of header guard
