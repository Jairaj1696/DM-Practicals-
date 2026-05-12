#include <iostream>
#include <vector>

using namespace std;

class RELATION {
private:
    vector<vector<int>> matrix;
    int n; // size of the set

public:
    void inputRelation() {
        cout << "Enter the number of elements in the set: ";
        cin >> n;
        matrix.assign(n, vector<int>(n, 0));

        cout << "Enter the relation matrix (" << n << "x" << n << ") row by row (0 or 1):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    bool isReflexive() {
        for (int i = 0; i < n; i++) {
            if (matrix[i][i] != 1) return false;
        }
        return true;
    }

    bool isSymmetric() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != matrix[j][i]) return false;
            }
        }
        return true;
    }

    bool isAntiSymmetric() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1) {
                    return false; // If aRb and bRa, then a must equal b
                }
            }
        }
        return true;
    }

    bool isTransitive() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (matrix[i][j] == 1 && matrix[j][k] == 1 && matrix[i][k] != 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void evaluateRelation() {
        bool reflexive = isReflexive();
        bool symmetric = isSymmetric();
        bool antiSymmetric = isAntiSymmetric();
        bool transitive = isTransitive();

        cout << "\n--- Relation Properties ---\n";
        cout << "Reflexive: " << (reflexive ? "Yes" : "No") << endl;
        cout << "Symmetric: " << (symmetric ? "Yes" : "No") << endl;
        cout << "Anti-Symmetric: " << (antiSymmetric ? "Yes" : "No") << endl;
        cout << "Transitive: " << (transitive ? "Yes" : "No") << endl;

        cout << "\n--- Classification ---\n";
        if (reflexive && symmetric && transitive) {
            cout << "The relation is an EQUIVALENCE relation.\n";
        } else if (reflexive && antiSymmetric && transitive) {
            cout << "The relation is a PARTIAL ORDER relation.\n";
        } else {
            cout << "The relation is NONE of the above (Neither Equivalence nor Partial Order).\n";
        }
    }
};

int main() {
    RELATION rel;
    cout << "--- Relation Evaluator ---\n";
    rel.inputRelation();
    rel.evaluateRelation();
    return 0;
}