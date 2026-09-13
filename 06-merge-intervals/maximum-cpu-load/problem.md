# Maximum CPU Load

- Source: [GeeksforGeeks](https://www.geeksforgeeks.org/maximum-cpu-load-from-the-given-list-of-jobs/)
- Platform: GeeksforGeeks

## Problem Description

Given an array of jobs with different time requirements, where each job consists of start time, end time, and CPU load. The task is to find the maximum CPU load at any time if all jobs are running on the same machine.

## Examples

### Example 1:
- **Input:** `jobs[] = {{1, 4, 3}, {2, 5, 4}, {7, 9, 6}}`
- **Output:** `7`
- **Explanation:** In the above given jobs, there are two jobs which overlap: Job `[1, 4, 3]` and `[2, 5, 4]` overlap during the interval `[2, 4]`. Hence, the maximum CPU Load at this instant will be `3 + 4 = 7`.

### Example 2:
- **Input:** `jobs[] = {{6, 7, 10}, {2, 4, 11}, {8, 12, 15}}`
- **Output:** `15`
- **Explanation:** There are no jobs that overlap. The maximum CPU Load will be `max(10, 11, 15) = 15`.

## Constraints

- `1 <= jobs.length <= 10^5`
- `0 <= start time < end time <= 10^6`
- `1 <= CPU load <= 10^4`
