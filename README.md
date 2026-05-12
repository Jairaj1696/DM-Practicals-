# DM-Practicals-

# Q1 Practical 1: Set Operations
# Question: Create a class SET. Create member functions to perform the following SET operations:

# is member: check whether an element belongs to the set or not and return value as true/false.
# powerset: list all the elements of the power set of a set.
# subset: Check whether one set is a subset of the other or not.
# union and Intersection of two Sets.
# complement: Assume Universal Set as per the input elements from the user.
# set Difference and Symmetric Difference between two sets.
# cartesian Product of Sets.
# Write a menu-driven program to perform the above functions on an instance of the SET class.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class SET {
private:
    vector<int> elements;

    // Helper to remove duplicates
    void removeDuplicates() {
        sort(elements.begin(), elements.end());
        elements.erase(unique(elements.begin(), elements.end()), elements.end());
    }

public:
    // Input elements into the set
    void inputSet() {
        int n, val;
        elements.clear();
        cout << "Enter number of elements: ";
        cin >> n;
        if (n > 0) cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) {
            cin >> val;
            elements.push_back(val);
        }
        removeDuplicates();
    }

    void display() const {
        cout << "{ ";
        for (int val : elements) cout << val << " ";
        cout << "}\n";
    }

    vector<int> getElements() const { return elements; }

    // 1. is member
    bool isMember(int val) const {
        return find(elements.begin(), elements.end(), val) != elements.end();
    }

    // 2. powerset
    void powerset() const {
        int n = elements.size();
        int powerSetSize = pow(2, n);
        cout << "{ ";
        for (int i = 0; i < powerSetSize; i++) {
            cout << "{";
            bool first = true;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    if (!first) cout << ", ";
                    cout << elements[j];
                    first = false;
                }
            }
            cout << "} ";
        }
        cout << "}\n";
    }

    // 3. subset
    bool isSubset(const SET& other) const {
        for (int val : elements) {
            if (!other.isMember(val)) return false;
        }
        return true;
    }

    // 4. union
    SET unionSet(const SET& other) const {
        SET result;
        result.elements = elements;
        for (int val : other.elements) {
            result.elements.push_back(val);
        }
        result.removeDuplicates();
        return result;
    }

    // 4. intersection
    SET intersectionSet(const SET& other) const {
        SET result;
        for (int val : elements) {
            if (other.isMember(val)) {
                result.elements.push_back(val);
            }
        }
        return result;
    }

    // 5. complement
    SET complement(const SET& universal) const {
        SET result;
        for (int val : universal.elements) {
            if (!isMember(val)) {
                result.elements.push_back(val);
            }
        }
        return result;
    }

    // 6. set difference
    SET difference(const SET& other) const {
        SET result;
        for (int val : elements) {
            if (!other.isMember(val)) {
                result.elements.push_back(val);
            }
        }
        return result;
    }

    // 6. symmetric difference
    SET symmetricDifference(const SET& other) const {
        SET u = unionSet(other);
        SET inter = intersectionSet(other);
        return u.difference(inter);
    }

    // 7. cartesian product
    void cartesianProduct(const SET& other) const {
        cout << "{ ";
        for (int a : elements) {
            for (int b : other.elements) {
                cout << "(" << a << ", " << b << ") ";
            }
        }
        cout << "}\n";
    }
};

int main() {
    SET setA, setB, universalSet;
    int choice;

    do {
        cout << "\n=== SET OPERATIONS MENU ===\n";
        cout << "1. is member\n2. powerset\n3. subset\n4. union & intersection\n";
        cout << "5. complement\n6. difference & symmetric difference\n7. cartesian product\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Input Set:\n"; setA.inputSet();
                int val; cout << "Enter element to check: "; cin >> val;
                cout << (setA.isMember(val) ? "True: Element belongs to the set." : "False: Element does not belong to the set.") << endl;
                break;
            }
            case 2:
                cout << "Input Set:\n"; setA.inputSet();
                cout << "Powerset: "; setA.powerset();
                break;
            case 3:
                cout << "Input Set A:\n"; setA.inputSet();
                cout << "Input Set B:\n"; setB.inputSet();
                cout << "Is A a subset of B? " << (setA.isSubset(setB) ? "Yes" : "No") << endl;
                break;
            case 4:
                cout << "Input Set A:\n"; setA.inputSet();
                cout << "Input Set B:\n"; setB.inputSet();
                cout << "Union: "; setA.unionSet(setB).display();
                cout << "Intersection: "; setA.intersectionSet(setB).display();
                break;
            case 5:
                cout << "Input Universal Set:\n"; universalSet.inputSet();
                cout << "Input Set A (must be subset of Universal):\n"; setA.inputSet();
                cout << "Complement of A: "; setA.complement(universalSet).display();
                break;
            case 6:
                cout << "Input Set A:\n"; setA.inputSet();
                cout << "Input Set B:\n"; setB.inputSet();
                cout << "Difference (A - B): "; setA.difference(setB).display();
                cout << "Symmetric Difference: "; setA.symmetricDifference(setB).display();
                break;
            case 7:
                cout << "Input Set A:\n"; setA.inputSet();
                cout << "Input Set B:\n"; setB.inputSet();
                cout << "Cartesian Product (A x B): "; setA.cartesianProduct(setB);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
