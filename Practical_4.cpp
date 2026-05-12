#include <iostream>
#include <vector>

using namespace std;

// Recursive function to find all solutions
void findSolutions(int n, int C, vector<int>& current_solution, int current_sum) {
    // Base case: If we have assigned values to all n variables
    if (current_solution.size() == n) {
        if (current_sum == C) {
            cout << "(";
            for (int i = 0; i < n; ++i) {
                cout << current_solution[i] << (i == n - 1 ? "" : ", ");
            }
            cout << ")\n";
        }
        return;
    }

    // Try assigning all possible values from 0 to C to the current variable
    for (int i = 0; i <= C - current_sum; ++i) {
        current_solution.push_back(i);
        findSolutions(n, C, current_solution, current_sum + i);
        current_solution.pop_back(); // backtrack
    }
}

int main() {
    int n, C;
    
    cout << "Equation format: x1 + x2 + ... + xn = C\n";
    cout << "Enter the number of variables (n): ";
    cin >> n;
    
    cout << "Enter the constant C (C <= 10): ";
    cin >> C;

    if (C > 10 || C < 0) {
        cout << "Invalid input. C must be between 0 and 10.\n";
        return 1;
    }

    if (n <= 0) {
        cout << "Number of variables must be greater than 0.\n";
        return 1;
    }

    vector<int> current_solution;
    cout << "\nAll possible non-negative integer solutions are:\n";
    findSolutions(n, C, current_solution, 0);

    return 0;
}