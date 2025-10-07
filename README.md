# Minimum-Cost Road Construction Project

**Project for the Algorithms and Data Structures Lab course** at the University of Bologna (A.Y. 2023/2024), based on official specifications.

---

## Project Objective

The goal is to design and implement a program in **ANSI C** that computes the minimum-cost path for constructing a road on a map represented as an `n x m` grid.  
The road must connect the starting cell `(0, 0)` to the destination cell `(n-1, m-1)`.

The total cost is determined by two factors:

1. A fixed cost **$C_{cell}$** for each cell traversed.  
2. A variable cost based on the elevation difference between adjacent cells, calculated as **$C_{height} \times (\Delta H)^2$**.

The total cost for a path of $k$ cells is:

$$
C_{total} = C_{cell} \times k + C_{height} \times \sum_{i=0}^{k-2} |H[x_{i}, y_{i}] - H[x_{i+1}, y_{i+1}]|^2
$$

The program must find a valid path that minimizes this total cost.

---

## Algorithmic Approach: Dijkstra's Algorithm

The problem can be modeled as finding the **shortest path on a weighted graph**.

### 1. Graph Modeling

- **Nodes:** Each cell `(i, j)` in the `n x m` grid is treated as a graph node. The total number of nodes is $V = n \times m$.  
- **Edges:** An edge exists between two nodes if the corresponding cells are adjacent (sharing a side). Each internal node has up to 4 outgoing edges (to N, S, E, W).  
- **Edge Weights:** The weight of an edge from cell `u` to an adjacent cell `v` represents the total cost of moving from `u` to `v`, including both the cell cost and the elevation cost:

$$
w(u, v) = C_{cell} + C_{height} \times (H_u - H_v)^2
$$

### 2. Dijkstra's Algorithm

Once modeled this way, the goal is to find the minimum-cost path from the source node `(0, 0)` to the target node `(n-1, m-1)`.  
Since all edge weights are non-negative, **Dijkstra's algorithm** is ideal for this problem.  

The algorithm maintains an estimate of the minimum cost to reach each node and updates these estimates iteratively starting from the source.

### 3. Priority Queue Management

The efficiency of Dijkstra’s algorithm critically depends on the **priority queue** implementation, used to select the next node to visit (the node with the smallest tentative distance).  
Starting from `(0,0)`, the algorithm explores the graph and builds the shortest-path tree until the destination node `(n-1, m-1)` is reached and extracted from the queue.

---

## Technologies and Project Constraints

- **Language:** ANSI C (C89/C90), strictly following course specifications.  
- **Compiler:** GCC with flags `-std=c90 -Wall -Wpedantic` to ensure full compliance and no warnings.  
- **Memory Management:** Careful attention to allocation and deallocation; absence of memory leaks and invalid access verified using **Valgrind** on Linux.  
- **Input/Output:** The program accepts an input file name via command line and outputs the minimum-cost path coordinates and total cost, formatted according to the specifications.

---

## Contact

 
* Alessio Bifulco:  `alessio.bifulco@studio.unibo.it`
