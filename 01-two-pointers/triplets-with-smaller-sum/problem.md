# Triplets with Smaller Sum

- Source: [GeeksforGeeks](https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1)
- Platform: GeeksforGeeks

## Problem Description

Given an array of distinct integers and an integer `sum`, count the unique triplets whose sum is strictly less than `sum`. Different permutations of the same three elements count as one triplet.

## Examples

Input: `sum = 2`, `arr = [-2, 0, 1, 3]`

Output: `2`

The valid triplets are `(-2, 0, 1)` and `(-2, 0, 3)`.

Input: `sum = 12`, `arr = [5, 1, 3, 4, 7]`

Output: `4`

## Constraints

- `1 <= sum <= 10^5`
- `3 <= arr.size() <= 10^3`
- `-10^3 <= arr[i] <= 10^3`
