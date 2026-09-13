# Employee Free Time

- Difficulty: Hard
- Source: [Naukri Code 360](https://www.naukri.com/code360/problems/employee-free-time_1171181)
- Platform: Naukri Code 360

## Problem Description

There are `N` Problem Setters in Coding Ninjas. Each of them has a unique ID between `0` to `N - 1`. A Problem Setter works in multiple non-overlapping time intervals during a day.

Formally, a Problem Setter having ID `i` works in $K_i$ non-overlapping intervals of the form $[T_1, T_2], [T_3, T_4], \dots, [T_{2K_i - 2}, T_{2K_i - 1}]$, where $T_i$ is in between $[0, 10^8]$ and $T_i \le T_{i+1}$. A day in Coding Ninjas starts from time `0` and ends at time $10^8$ (both inclusive).

You are given `N` sorted lists of non-overlapping intervals, where the $i$-th list gives a schedule (list of intervals in which the problem setter works) of a Problem Setter having ID `i`. Your task is to find a sorted list of non-overlapping intervals in which all problem setters are free. If there are multiple possible such lists, output the list which is minimum in length.

### Notes:
1. In sorted order, interval $[T_1, T_2]$ comes before $[T_3, T_4]$ if either $T_1 < T_3$, or ($T_1 == T_3$ and $T_2 < T_4$).
2. An interval $[T_1, T_2]$ represents time $T_1, T_1 + 1, T_1 + 2, \dots, T_2$, i.e., all integers between $T_1, T_2$ (both $T_1$ and $T_2$ inclusive).
3. For simplicity, we represent the list of intervals in a 1D array where every two numbers show an interval, e.g., list `[1, 3, 5, 7, 9, 11]` represents intervals `[1, 3]`, `[5, 7]` and `[9, 11]`.
4. It is guaranteed that there will be at least one interval where all problem setters are free.

## Examples

### Example 1
**Schedule**: `[[1, 2, 5, 6], [1, 2], [5, 10]]`
- Setter 0 works in `[1, 2]`, `[5, 6]`. Free: `[0, 0]`, `[3, 4]`, `[7, 10^8]`.
- Setter 1 works in `[1, 2]`. Free: `[0, 0]`, `[3, 10^8]`.
- Setter 2 works in `[5, 10]`. Free: `[0, 4]`, `[11, 10^8]`.

Common free intervals for all 3 setters: `[0, 0]`, `[3, 4]`, and `[11, 10^8]`.  
**Output**: `[0, 0, 3, 4, 11, 100000000]`

### Sample Test Case 1

**Input:**
```text
2
1
1
10 20
3
2
1 2 5 6
1
1 2
1
5 10
```

**Output:**
```text
0 9 21 100000000
0 0 3 4 11 100000000
```

**Explanation:**
- Test Case 1: There is only one problem setter, who is busy during interval `[10, 20]`. A day is given by `[0, 10^8]`, thus he is free between `[0, 9]` and `[21, 10^8]`.
- Test Case 2: Refer to Example 1.

### Sample Test Case 2

**Input:**
```text
2
1
1
1 100000000
3
2
1 2 5 6
3
1 1 2 2 3 3
1
0 2
```

**Output:**
```text
0 0
4 4 7 100000000
```

## Constraints

- `1 <= T <= 10` (Number of test cases)
- `1 <= N <= 1000` (Number of problem setters)
- `1 <= K <= 1000` (Number of intervals per setter)
- Time Limit: `1 sec`
