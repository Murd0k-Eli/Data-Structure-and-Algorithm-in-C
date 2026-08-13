### Foundations
*   **Arrays**: Linear data structures for storing elements.
    *   **Traversal**: Visiting every element once.
    *   **Insertion**: Adding an element at a specific index.
    *   **Deletion**: Removing an element from a specific index.
    *   **Searching**: Finding the index of a target value.
    *   **Sorting**: Arranging elements in a specific order.
    *   **Prefix/Suffix**: Pre-calculating cumulative data from the start or end.   
*   **Strings**: Sequences of characters.
    *   **Traversal**: Iterating through characters.
    *   **Pattern Match**: Finding a substring within a string.
    *   **Anagram**: Checking if two strings have the same characters in different orders.
    *   **Palindrome**: Checking if a string reads the same backward.
    *   **Hashing**: Converting strings to numeric values for fast comparison.
    *   **Substrings**: Contiguous sequences of characters within a string.
*   **Math & Number Theory**:
    *   **GCD/LCM**: Greatest Common Divisor and Least Common Multiple.
    *   **Prime/Sieve**: Identifying prime numbers (e.g., Sieve of Eratosthenes).
    *   **Modular**: Arithmetic performed under a modulus to prevent overflow.
    *   **Exponent**: Calculating powers efficiently (e.g., Binary Exponentiation).
    *   **Combinatorics**: Counting permutations and combinations.
*   **Bit Manipulation**:
    *   **AND/OR/XOR**: Logical operations on binary bits.
    *   **Shifts**: Moving bits left or right.
    *   **Masking**: Using bits to isolate or modify specific data.
    *   **Count Set Bits**: Counting the number of 1s in binary.
    *   **Power of 2**: Checking if a number is $2^n$.
*   **Hashing**:
    *   **Hash Map**: Key-value pairs for $O(1)$ average access.
    *   **Hash Set**: Collection of unique elements.
    *   **Frequency Count**: Tracking occurrences of elements.
    *   **Grouping**: Categorizing elements by a common key.
    *   **Collision Handling**: Managing cases where two keys hash to the same index.
*   **Prefix Sum**:
    *   **1D/2D Prefix Sum**: Pre-calculating sums to answer range queries in $O(1)$.
    *   **Range Sum**: Sum of elements between two indices.
    *   **Subarray Sum**: Finding sums of contiguous segments.
*   **Difference Array**:
    *   **Range Update**: Efficiently adding a value to a range of elements.
    *   **Efficiency Updates**: Reducing range updates from $O(N)$ to $O(1)$.
    *   **Prefix Conversions**: Converting a difference array back to the original array.
*   **Matrix Traversal**:
    *   **Row/Column Wise**: Iterating through rows or columns.
    *   **Spiral Order**: Visiting elements in a clockwise spiral.
    *   **Diagonals**: Iterating through diagonal elements.

### Linear Data Structures
*   **Two Pointers**: Uses two indices to traverse a data structure. Common for finding pairs/triplets that sum to a target, removing duplicates in-place, or partitioning arrays.
*   **Sliding Window**: Tracks a contiguous subset of data. Fixed windows handle constant sizes; variable windows expand/shrink to find optimal substrings or subarrays.
*   **Monotonic Stack**: Maintains elements in a specific order (increasing/decreasing). Ideal for "next greater/smaller element" problems and calculating histogram areas.
*   **Stack**: LIFO (Last-In-First-Out) structure. Used for expression parsing (infix to postfix), balancing parentheses, and managing state in backtracking.
*   **Queue**: FIFO (First-In-First-Out) structure. Used for standard task scheduling, circular buffers, and Breadth-First Search (BFS) traversal.
*   **Deque**: Double-ended queue. Supports insertions/deletions at both ends; useful for sliding window maximums and palindrome verification.
*   **Linked List**: Nodes connected via pointers.
    *   **Singly**: One-way traversal; used for basic lists and merges.
    *   **Circular**: Last node links to first; used for round-robin scheduling (e.g., Josephus problem).
    *   **Doubly**: Two-way traversal; enables efficient deletions and LRU (Least Recently Used) cache implementation.
### Searching and Sorting
*   **Binary Search**
    *   **Example**: Finding the index of a target number in a sorted array `[1, 3, 5, 7, 9]`.
    *   **Variations**: 
        *   *Lower Bound*: Finding the first element $\ge$ target.
        *   *Upper Bound*: Finding the first element $>$ target.
        *   *Rotated Sorted Array*: Searching in an array that has been shifted (e.g., `[4, 5, 6, 7, 0, 1, 2]`).

*   **Binary Search on Answer**
    *   **Example**: "Koko Eating Bananas" — Finding the minimum eating speed $K$ such that all bananas are eaten within $H$ hours.
    *   **Variations**: 
        *   *Minimize Maximum*: Finding the smallest possible maximum value (e.g., Split Array Largest Sum).
        *   *Maximize Minimum*: Finding the largest possible minimum value (e.g., Aggressive Cows).

*   **Sorting Algorithms**
    *   **Merge Sort**
        *   **Example**: Sorting a linked list by recursively splitting it and merging sorted halves.
        *   **Variations**: *Iterative Merge Sort* (bottom-up approach to avoid recursion stack).
    *   **Quick Sort**
        *   **Example**: Sorting an array by picking a pivot and partitioning elements around it.
        *   **Variations**: *Randomized Quick Sort* (picking a random pivot to avoid $O(N^2)$ worst-case), *3-Way Quick Sort* (handling duplicate elements efficiently).
    *   **Counting Sort**
        *   **Example**: Sorting a list of exam scores (0-100) by counting occurrences of each score.
        *   **Variations**: *Stable Counting Sort* (preserving relative order of equal elements).
    *   **Radix Sort**
        *   **Example**: Sorting a list of large integers by sorting them digit by digit from Least Significant Digit (LSD) to Most Significant Digit (MSD).
        *   **Variations**: *MSD Radix Sort* (recursive approach starting from the first digit).
    *   **Bucket Sort**
        *   **Example**: Sorting a list of floating-point numbers uniformly distributed between 0 and 1.
        *   **Variations**: *Bucket Sort with different internal sorts* (using Insertion Sort or Quick Sort inside each bucket).

*   **Divide and Conquer**
    *   **Example**: Finding the maximum and minimum elements in an array by splitting it into two halves.
    *   **Variations**: 
        *   *Binary Search* (Divide and discard).
        *   *Closest Pair of Points* (Divide, solve sub-problems, and check the "strip" across the divide).
        *   *Strassen's Matrix Multiplication* (Reducing the number of multiplications for matrices).
### Recursion
*   **Basic Recursion**: A function calling itself to solve a smaller instance of the same problem.
*   **Backtracking**: Exploring all possibilities and undoing steps when a path fails.
*   **Branch and Bound**: Optimizing state-space search by pruning branches that cannot yield a solution.

### Trees
*   **Binary Tree**: Each node has at most two children.
*   **Binary Search Tree (BST)**: Left child < Parent < Right child.
*   **AVL/Red-Black Tree**: Self-balancing BSTs to ensure $O(\log N)$ operations.
*   **Segment Tree**: Range query and update structure.
*   **Fenwick Tree (BIT)**: Efficient prefix sums and updates.
*   **Trie**: Prefix tree used for dictionary/string lookups.
*   **Heap**: Priority-based tree (Min-Heap/Max-Heap).
*   **Priority Queue**: Queue where elements are dequeued based on priority.
*   **N-ary Tree**: Nodes can have any number of children.

### Graphs
*   **Representation**: Adjacency List or Adjacency Matrix.
*   **DFS/BFS**: Depth-First Search (stack/recursion) and Breadth-First Search (queue).
*   **Topological Sort**: Linear ordering of vertices for Directed Acyclic Graphs (DAGs).
*   **Union Find (DSU)**: Tracking connected components.
*   **Dijkstra**: Shortest path from a source (non-negative weights).
*   **Bellman-Ford**: Shortest path (handles negative weights).
*   **Floyd-Warshall**: All-pairs shortest path.
*   **Prim/Kruskal**: Algorithms for Minimum Spanning Tree (MST).
*   **SCC**: Strongly Connected Components (e.g., Tarjan's or Kosaraju's).
*   **Bridges/Articulation Points**: Finding critical edges/nodes that disconnect a graph.
*   **Eulerian/Hamiltonian Paths**: Visiting every edge once vs. every vertex once.
*   **Bipartite Graph**: Graph whose vertices can be divided into two independent sets.
*   **A* Search**: Heuristic-based shortest path search.

### Dynamic Programming (DP)
*   **1D/2D DP**: Solving problems by storing results of sub-problems in arrays.
*   **Knapsack**: Optimizing value within a weight limit.
*   **LCS/LIS**: Longest Common Subsequence and Longest Increasing Subsequence.
*   **Matrix Chain Multiplication**: Optimizing the order of matrix multiplications.
*   **DP on Trees/Graphs**: Solving DP problems where states are nodes in a graph.
*   **Bitmask DP**: Using bitmasks to represent subsets of states.
*   **Interval DP**: Solving problems based on ranges $[i, j]$.

### Greedy
*   **Activity Selection**: Picking the maximum number of non-overlapping activities.
*   **Huffman Coding**: Optimal prefix coding for data compression.
*   **Interval Scheduling**: Managing time slots for maximum efficiency.
*   **Greedy with Heap**: Using a priority queue to always pick the local optimum.

### Advanced Strings
*   **KMP/Rabin-Karp**: Efficient pattern matching algorithms.
*   **Z-Algorithm**: Finding all occurrences of a pattern in linear time.
*   **Manacher's Algorithm**: Finding the longest palindromic substring in $O(N)$.
*   **Suffix Array/Automation**: Advanced structures for complex string queries.

### Range Queries & Advanced Trees
*   **Sparse Table**: $O(1)$ range minimum queries after $O(N \log N)$ preprocessing.
*   **Euler Tour Tree**: Flattening a tree into an array for range queries.
*   **LCA**: Lowest Common Ancestor of two nodes in a tree.