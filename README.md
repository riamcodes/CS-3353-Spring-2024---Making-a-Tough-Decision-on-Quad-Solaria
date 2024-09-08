# CS-3353-Spring-2024---Making-a-Tough-Decision-on-Quad-Solaria
A recursive algorithm project solving the majority voting problem on Quad-Solaria using two different methods with O(n log n) and O(n) complexities.
This repository contains two recursive algorithm implementations designed to determine whether a particular object appears in more than half of a vector of objects, based on a voting system from the fictional planet Quad-Solaria. The algorithms leverage recursion and divide-and-conquer strategies to solve the problem efficiently.

Features
Version 1: Implements a recursive function with a time complexity of O(n log n) using a divide-and-conquer approach to solve the majority voting problem.
Version 2: Implements a more efficient recursive function with time complexity O(n), based on pairing and reducing the number of elements at each step.
Algorithm Highlights
Recursive Decision Making: Both versions rely on recursive techniques without sorting the objects or modifying the original vector.
Efficiency: Version 1 offers an O(n log n) solution, while Version 2 optimizes the process to O(n), making it faster for large data sets.
Class and Operator Constraints: The program follows strict requirements for handling objects of the Stuff3 class, including overloaded operators for comparison and assignment.
Getting Started
The implementation can be found in Prog3.cpp.
Sample tests are available in Prog3_test.cpp.
The Stuff3.h and Stuff3.cpp files provide the necessary class structure for the program.
