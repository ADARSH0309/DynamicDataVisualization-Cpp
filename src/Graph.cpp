#include "Graph.h"
#include <queue>
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

Graph::Graph(int vertices) : V(vertices) {
    adjList.resize(vertices);
    adjMatrix.assign(vertices, vector<int>(vertices, 0));
}

void Graph::addEdge(int u, int v, int weight) {
    adjList[u].emplace_back(v, weight);
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight; // For undirected graph
}

void Graph::removeEdge(int u, int v) {
    adjList[u].remove_if([v](pair<int, int> edge) { return edge.first == v; });
    adjMatrix[u][v] = 0;
    adjMatrix[v][u] = 0; // For undirected graph
}

void Graph::BFS(int start) {
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto &[neighbor, weight] : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

void Graph::DFSUtil(int node, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (auto &[neighbor, weight] : adjList[node]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, visited);
        }
    }
}

void Graph::DFS(int start) {
    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    DFSUtil(start, visited);
    cout << endl;
}

void Graph::dijkstra(int start) {
    vector<int> dist(V, numeric_limits<int>::max());
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &[v, weight] : adjList[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    cout << "Shortest distances from node " << start << ": ";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": " << dist[i] << ", ";
    }
    cout << endl;
}

void Graph::bellmanFord(int start) {
    vector<int> dist(V, numeric_limits<int>::max());
    dist[start] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (auto &[v, weight] : adjList[u]) {
                if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 0; u < V; ++u) {
        for (auto &[v, weight] : adjList[u]) {
            if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative weight cycle!" << endl;
                return;
            }
        }
    }

    cout << "Shortest distances from node " << start << ": ";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": " << dist[i] << ", ";
    }
    cout << endl;
}

void Graph::primMST() {
    vector<int> key(V, numeric_limits<int>::max());
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);
    key[0] = 0;

    for (int i = 0; i < V - 1; ++i) {
        int u = -1;

        // Find the vertex with the smallest key value not in MST
        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true;

        for (auto &[v, weight] : adjList[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    cout << "Minimum Spanning Tree (Prim's):" << endl;
    for (int v = 1; v < V; ++v) {
        cout << parent[v] << " - " << v << endl;
    }
}

void Graph::kruskalMST() {
    vector<tuple<int, int, int>> edges;
    for (int u = 0; u < V; ++u) {
        for (auto &[v, weight] : adjList[u]) {
            edges.emplace_back(weight, u, v);
        }
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(V);
    iota(parent.begin(), parent.end(), 0);

    auto find = [&](int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    };

    auto unionSet = [&](int x, int y) {
        parent[find(x)] = find(y);
    };

    cout << "Minimum Spanning Tree (Kruskal's):" << endl;
    for (auto &[weight, u, v] : edges) {
        if (find(u) != find(v)) {
            cout << u << " - " << v << " : " << weight << endl;
            unionSet(u, v);
        }
    }
}
