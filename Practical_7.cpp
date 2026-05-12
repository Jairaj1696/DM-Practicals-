#include <iostream>
#include <vector>

using namespace std;

int main() {
    int v, e;
    cout << "Enter the number of vertices in the graph: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    // Array of vectors to represent the adjacency list
    vector<vector<int>> adjList(v);

    cout << "Enter the edges (pairs of connected vertices, 0-indexed):\n";
    for (int i = 0; i < e; ++i) {
        int u, w;
        cin >> u >> w;
        // Since it's an undirected graph, add edges both ways
        adjList[u].push_back(w);
        adjList[w].push_back(u);
    }

    bool isComplete = true;
    for (int i = 0; i < v; ++i) {
        // In a complete graph without self-loops, every vertex connects to (v - 1) other vertices
        if (adjList[i].size() != v - 1) {
            isComplete = false;
            break;
        }
    }

    if (isComplete) {
        cout << "\nThe given graph is a COMPLETE graph.\n";
    } else {
        cout << "\nThe given graph is NOT a complete graph.\n";
    }

    return 0;
}