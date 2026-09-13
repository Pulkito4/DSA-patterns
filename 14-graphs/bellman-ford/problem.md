# Bellman Ford

- Source: [GeeksforGeeks](https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1)
- Platform: GeeksforGeeks

## Problem Description

Given a weighted graph with `V` vertices numbered from `0` to `V - 1` and `E` edges, represented by a 2D array `edges[][]`, where `edges[i] = [u, v, w]` represents a directed edge from node `u` to `v` having `w` edge weight. You are also given a source vertex `src`.

Compute the shortest distances from the `src` to all other vertices. If a vertex is unreachable from the `src`, its distance should be marked as `10^8`. Additionally, if the graph contains a negative weight cycle, return `[-1]` to indicate that shortest paths cannot be reliably computed.

## Examples

### Example 1:
- **Input:** `V = 5, edges[][] = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]], src = 0`
- **Output:** `[0, 5, 6, 6, 7]`
- **Explanation:**
  - For `0` to `1`, distance is `5` (`0 -> 1`).
  - For `0` to `2`, distance is `6` (`0 -> 1 -> 2`).
  - For `0` to `3`, distance is `6` (`0 -> 1 -> 2 -> 4 -> 3`).
  - For `0` to `4`, distance is `7` (`0 -> 1 -> 2 -> 4`).

### Example 2:
- **Input:** `V = 4, edges[][] = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]], src = 0`
- **Output:** `[-1]`
- **Explanation:** The graph contains a negative weight cycle formed by the path `1 -> 2 -> 3 -> 1`, where the total weight of the cycle is negative.

## Constraints

- `1 <= V <= 100`
- `1 <= E = edges.size() <= V * (V - 1)`
- `-1000 <= w <= 1000`
