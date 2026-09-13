# DFS of Graph

- Source: [GeeksforGeeks](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1)
- Platform: GeeksforGeeks

## Problem Description

Given a connected undirected graph containing `V` vertices represented by a 2D adjacency list `adj[][]`, where each `adj[i]` represents the list of vertices connected to vertex `i`. Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.

> **Note:** Do traverse in the same order as they are in the given adjacency list.

## Examples

### Example 1:
- **Input:** `adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]`

<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700169/Web/Other/d12b07e5-1ee7-4a6a-8ff4-3b10b06ba67e_1685086551.png" alt="Example 1 Graph" style="max-width: 400px;" />

- **Output:** `[0, 2, 4, 3, 1]`
- **Explanation:** Starting from 0, the DFS traversal proceeds as follows:
  - Visit 0 → Output: 0
  - Visit 2 (first neighbor of 0) → Output: 0, 2
  - Visit 4 (first neighbor of 2) → Output: 0, 2, 4
  - Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3
  - Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1

### Example 2:
- **Input:** `adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]`

<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700169/Web/Other/2efc2250-9bbd-424d-b638-348500fd59e8_1685086551.png" alt="Example 2 Graph" style="max-width: 400px;" />

- **Output:** `[0, 1, 2, 3, 4]`
- **Explanation:** Starting from 0, the DFS traversal proceeds as follows:
  - Visit 0 → Output: 0
  - Visit 1 (first neighbor of 0) → Output: 0, 1
  - Visit 2 (first neighbor of 1) → Output: 0, 1, 2
  - Visit 3 (first neighbor of 2) → Output: 0, 1, 2, 3
  - Backtrack to 2 and visit 4 → Final Output: 0, 1, 2, 3, 4

## Constraints

- `1 <= V = adj.size() <= 10^4`
- `0 <= adj[i][j] <= 10^4`
