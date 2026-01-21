*This project has been created as part of the 42 curriculum by melshata.*

# Push_swap

## Description
**push_swap** is a project where you must sort a stack of integers using a limited set of instructions and a secondary stack. The goal is to find the most efficient sequence of moves to sort the data. 

For this project, I implemented the **Radix Sort algorithm** in a Linked List structure. This approach uses bitwise operations to sort numbers by their binary representation. To handle negative numbers and optimize the process, I first "indexed" the input values from 0 to (N-1) based on their relative size.

## Instructions

### How to Build
To compile the project and generate the `push_swap` executable, run:
"make"

### How to Run
Provide a list of integers as arguments. The program will output the operations required to sort them:
./push_swap 3 2 5 1 4
to count the number of operations:
./push_swap 3 2 5 1 4 | wc -l

## Resources
Algorithm Logic
Radix Sort Explained: "https://www.youtube.com/watch?v=KJTyDYoiGU4"

### AI Usage
AI was utilized for the following tasks:

- Helping to debug the moves and iteration loops to ensure every node was processed correctly.
- Explain and visualize code flow to make error detecting more efficient.