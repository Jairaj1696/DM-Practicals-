#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Permutation without repetition using C++ STL
void permuteWithoutRepetition(vector<int> arr) {
    sort(arr.begin(), arr.end());
    cout << "Permutations without repetition:\n";
    do {
        for (int val : arr) cout << val << " ";
        cout << endl;
    } while (next_permutation(arr.begin(), arr.end()));
}

// Permutation with repetition using recursive backtracking
void permuteWithRepetition(const vector<int>& arr, vector<int>& current, int n) {
    if (current.size() == n) {
        for (int val : current) cout << val << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        current.push_back(arr[i]);
        permuteWithRepetition(arr, current, n);
        current.pop_back(); // backtrack
    }
}

int main() {
    int n, choice;
    cout << "Enter the number of digits: ";
    cin >> n;

    vector<int> digits(n);
    cout << "Enter the digits: ";
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    cout << "\n1. Permutations without repetition\n";
    cout << "2. Permutations with repetition\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        permuteWithoutRepetition(digits);
    } else if (choice == 2) {
        vector<int> current;
        cout << "Permutations with repetition:\n";
        permuteWithRepetition(digits, current, n);
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}