#include <iostream>
#include <vector>

using namespace std;

int main() {
    int v, e;
    cout << "Enter the number of vertices in the Directed Graph: ";
    cin >> v;
    cout << "Enter the number of directed edges: ";
    cin >> e;

    vector<int> in_degree(v, 0);
    vector<int> out_degree(v, 0);

    cout << "Enter the directed edges (source to destination, 0-indexed):\n";
    for (int i = 0; i < e; ++i) {
        int source, dest;
        cin >> source >> dest;
        
        // Edge goes from 'source' to 'dest'
        out_degree[source]++;
        in_degree[dest]++;
    }

    cout << "\n--- Degree Summary ---\n";
    cout << "Vertex\tIn-Degree\tOut-Degree\n";
    for (int i = 0; i < v; ++i) {
        cout << i << "\t" << in_degree[i] << "\t\t" << out_degree[i] << "\n";
    }

    return 0;
}