# 0 - 1 Knapsack Problem

- Source: [GeeksforGeeks](https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1)
- Platform: GeeksforGeeks

## Problem Description

Given two arrays, `val[]` and `wt[]`, where each element represents the value and weight of an item respectively, and an integer `W` representing the maximum capacity of the knapsack (the total weight it can hold).

Put the items into the knapsack such that the total value obtained is maximum without exceeding the capacity `W`.

> **Note:** You can either include an item completely or exclude it entirely — fractional selection of items is not allowed. Each item is available only once.

## Examples

### Example 1:
- **Input:** `W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]`
- **Output:** `3`
- **Explanation:** Choose the last item, which weighs 1 unit and has a value of 3.

### Example 2:
- **Input:** `W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6]`
- **Output:** `0`
- **Explanation:** Every item has a weight exceeding the knapsack's capacity (3).

### Example 3:
- **Input:** `W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3]`
- **Output:** `80`
- **Explanation:** Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.

## Constraints

- `1 <= W, val.size(), val[i], wt.size(), wt[i] <= 10^3`
- `wt.size() == val.size()`
