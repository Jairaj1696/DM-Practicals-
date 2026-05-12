#include <iostream>
#include <vector>

using namespace std;

int main() {
    int v;
    cout << "Enter the number of vertices in the graph: ";
    cin >> v;

    vector<vector<int>> matrix(v, vector<int>(v));

    cout << "Enter the Adjacency Matrix row by row (0s and 1s):\n";
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            cin >> matrix[i][j];
        }
    }

    bool isComplete = true;
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            if (i == j) {
                if (matrix[i][j] != 0) isComplete = false; // Check for self-loops
            } else {
                if (matrix[i][j] != 1) isComplete = false; // Check for missing edges
            }
        }
    }

    if (isComplete) {
        cout << "\nThe given graph is a COMPLETE graph.\n";
    } else {
        cout << "\nThe given graph is NOT a complete graph.\n";
    }

    return 0;
}