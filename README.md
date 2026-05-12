# C++ Discrete Mathematics Practicals: Questions and Test Cases

This document contains the problem statements for 8 practical assignments, along with unique Input/Output simulations to verify the correctness of the C++ programs.

---

### Practical 1: Set Operations
**Question:**
Create a class `SET`. Create member functions to perform the following SET operations:
1) is member: check whether an element belongs to the set or not and return value as true/false.
2) powerset: list all the elements of the power set of a set.
3) subset: Check whether one set is a subset of the other or not.
4) union and Intersection of two Sets.
5) complement: Assume Universal Set as per the input elements from the user.
6) set Difference and Symmetric Difference between two sets.
7) cartesian Product of Sets.

Write a menu-driven program to perform the above functions on an instance of the SET class.

<details>
<summary><b>View Example Input/Output</b></summary>

```text
=== SET OPERATIONS MENU ===
1. is member
2. powerset
...
Enter your choice: 2
Input Set:
Enter number of elements: 3
Enter the elements: 2 3 5
Powerset: { {} {2} {3} {2, 3} {5} {2, 5} {3, 5} {2, 3, 5} }

=== SET OPERATIONS MENU ===
Enter your choice: 6
Input Set A:
Enter number of elements: 4
Enter the elements: 2 3 5 7
Input Set B:
Enter number of elements: 3
Enter the elements: 5 7 11
Difference (A - B): { 2 3 }
Symmetric Difference: { 2 3 11 }
```

</details>

---

### Practical 2: Relations and Matrix Notation
**Question:**
Create a class `RELATION`, use Matrix notation to represent a relation. Include member functions to check if the relation is Reflexive, Symmetric, Anti-symmetric, Transitive. Using these functions check whether the given relation is: Equivalence or Partial Order relation or None.

<details>
<summary><b>View Example Input/Output</b></summary>

*(Testing a Partial Order relation representing "less than or equal to" on the set {1, 2, 3})*
```text
--- Relation Evaluator ---
Enter the number of elements in the set: 3
Enter the relation matrix (3x3) row by row (0 or 1):
1 1 1
0 1 1
0 0 1

--- Relation Properties ---
Reflexive: Yes
Symmetric: No
Anti-Symmetric: Yes
Transitive: Yes

--- Classification ---
The relation is a PARTIAL ORDER relation.
```

</details>

---

### Practical 3: Permutations
**Question:**
Write a Program that generates all the permutations of a given set of digits, with or without repetition.

<details>
<summary><b>View Example Input/Output</b></summary>

```text
Enter the number of digits: 2
Enter the digits: 7 9

1. Permutations without repetition
2. Permutations with repetition
Enter your choice: 2
Permutations with repetition:
7 7 
7 9 
9 7 
9 9 
```

</details>

---

### Practical 4: Brute Force Equation Solver
**Question:**
For any number $n$, write a program to list all the solutions of the equation $x_1 + x_2 + x_3 + \dots + x_n = C$, where $C$ is a constant ($C \le 10$) and $x_1, x_2, x_3, \dots, x_n$ are nonnegative integers, using brute force strategy.

<details>
<summary><b>View Example Input/Output</b></summary>

*(Solving for x1 + x2 + x3 = 3)*
```text
Equation format: x1 + x2 + ... + xn = C
Enter the number of variables (n): 3
Enter the constant C (C <= 10): 3

All possible non-negative integer solutions are:
(0, 0, 3)
(0, 1, 2)
(0, 2, 1)
(0, 3, 0)
(1, 0, 2)
(1, 1, 1)
(1, 2, 0)
(2, 0, 1)
(2, 1, 0)
(3, 0, 0)
```

</details>

---

### Practical 5: Polynomial Evaluation
**Question:**
Write a Program to evaluate a polynomial function. (For example store $f(x) = 4n^2 + 2n + 9$ in an array and for a given value of $n$, say $n = 5$, compute the value of $f(n)$).

<details>
<summary><b>View Example Input/Output</b></summary>

*(Evaluating f(x) = 2x^3 - x + 5 at x = 3)*
```text
Enter the maximum degree of the polynomial: 3
Enter the coefficients:
Coefficient for x^3: 2
Coefficient for x^2: 0
Coefficient for x^1: -1
Coefficient for x^0: 5

Enter the value of n (the value to evaluate the function at): 3

The value of the polynomial f(3) is: 56
```

</details>

---

### Practical 6: Complete Graph (Adjacency Matrix)
**Question:**
Write a Program to check if a given graph is a complete graph. Represent the graph using the Adjacency Matrix representation.

<details>
<summary><b>View Example Input/Output</b></summary>

*(Testing a valid K4 complete graph)*
```text
Enter the number of vertices in the graph: 4
Enter the Adjacency Matrix row by row (0s and 1s):
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0

The given graph is a COMPLETE graph.
```

</details>

---

### Practical 7: Complete Graph (Adjacency List)
**Question:**
Write a Program to check if a given graph is a complete graph. Represent the graph using the Adjacency List representation.

<details>
<summary><b>View Example Input/Output</b></summary>

*(Testing a graph missing one edge between vertex 2 and 3)*
```text
Enter the number of vertices in the graph: 4
Enter the number of edges: 5
Enter the edges (pairs of connected vertices, 0-indexed):
0 1
0 2
0 3
1 2
1 3

The given graph is NOT a complete graph.
```

</details>

---

### Practical 8: In-degree and Out-degree of a Directed Graph
**Question:**
Write a Program to accept a directed graph G and compute the in-degree and out-degree of each vertex.

<details>
<summary><b>View Example Input/Output</b></summary>

```text
Enter the number of vertices in the Directed Graph: 4
Enter the number of directed edges: 5
Enter the directed edges (source to destination, 0-indexed):
0 1
1 2
2 0
3 0
3 1

--- Degree Summary ---
Vertex  In-Degree       Out-Degree
0       2               1
1       2               1
2       1               1
3       0               2
```

</details>