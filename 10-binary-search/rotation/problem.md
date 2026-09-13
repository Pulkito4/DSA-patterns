# Find Kth Rotation

- Source: [GeeksforGeeks](https://www.geeksforgeeks.org/problems/rotation4723/1)
- Platform: GeeksforGeeks

## Problem Description

Given an increasing sorted rotated array `arr[]` of distinct integers. The array is right-rotated `k` times. Find the value of `k`.

## Examples

### Example 1:
- **Input:** `arr[] = [5, 1, 2, 3, 4]`
- **Output:** `1`
- **Explanation:** The given array is `[5, 1, 2, 3, 4]`. The original sorted array is `[1, 2, 3, 4, 5]`. We can see that the array was rotated 1 time to the right.

### Example 2:
- **Input:** `arr[] = [1, 2, 3, 4, 5]`
- **Output:** `0`
- **Explanation:** The given array is not rotated.

## Constraints

- `1 <= arr.size() <= 10^5`
- `1 <= arr[i] <= 10^7`
