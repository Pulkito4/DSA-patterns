You are taking over a DSA repository task for the user. Read this entire handoff before editing.

## User Goal

Maintain a pattern-based DSA practice repository. The user codes primarily in C++ and uses the LeetCode VS Code extension format.

## Repository Structure

Workspace root:
`D:\Coding stuff (self practice and projects and all)\DSA`

Pattern folders already exist:
- `01-two-pointers`
- `02-fast-and-slow-pointers`
- `03-sliding-window`
- `04-kadane-pattern`
- `05-prefix-sum`
- `06-merge-intervals`
- `07-in-place-reversal-of-a-linked-list`
- `08-stack`
- `09-hash-maps`
- `10-binary-search`
- `11-heap-pattern`
- `12-recursion-and-backtracking`
- `13-tree-pattern`
- `14-graphs`
- `15-dynamic-programming`
- `16-greedy`

Each problem should be a readable slug folder, for example:
`01-two-pointers/3sum/`

Each problem folder should contain:
- `problem.md` with the problem statement, examples, constraints, source link, and platform.
- `approach-01.cpp`, `approach-02.cpp`, etc. for accepted solution variants.

Do not create a separate `leetcode-problems` folder. Do not recreate any generator script or bulk-generation folder. Work sequentially and inspect existing files before editing.

## LeetCode File Format

Every LeetCode C++ solution must remain compatible with the LeetCode extension, using the existing format:

```cpp
/*
 * @lc app=leetcode id=<id> lang=cpp
 *
 * [<id>] <title>
 */

// @lc code=start
class Solution {
    // exact submitted solution, including the user's original comments
};
// @lc code=end
```

## Critical Comment Requirement

The current repository may contain normalized/reconstructed LeetCode code whose personal comments were lost. Do not assume existing code is exact.

Use the authenticated LeetCode MCP:
1. Call `get_all_submissions` for each relevant LeetCode slug.
2. Restrict to submissions from 2026 when the task is about the user's 2026 work.
3. Keep accepted C++ submissions, including multiple accepted variants.
4. Fetch each accepted submission with `get_problem_submission_report`.
5. Compare the fetched `detail.code` against the local `approach-*.cpp` files.
6. Replace local code with the exact fetched source when it differs, preserving every original comment. Do not add artificial comments such as `Restored from the accepted 2026 LeetCode submission.`
7. Keep the LeetCode header and `// @lc code=start/end` wrapper, but do not normalize or rewrite the submitted code inside it.
8. Do not overwrite user edits made after this handoff without checking them first.

The user explicitly removed the artificial restoration-marker comments and did not stage those changes. Respect the current working tree and inspect current file contents before changing anything.

## Existing Sheet Work

A Google Sheet named `DSA patterns Cheat Sheet` was previously parsed. Its LeetCode problems were organized through Prefix Sum, and five GFG problems were added through Prefix Sum.

Existing GFG problem folders added:
- `01-two-pointers/rearrange-0-and-1`
- `01-two-pointers/triplets-with-smaller-sum`
- `03-sliding-window/maximum-sum-subarray-of-size-k`
- `03-sliding-window/longest-substring-with-k-distinct-characters`
- `04-kadane-pattern/minimum-subarray-sum`

Their accepted GFG 2026 C++ submissions were fetched through the authenticated browser and written with their original visible comments. Their Markdown was repaired with descriptions, examples, and constraints.

## Gemini PDF: Additional Questions Discussed

The attached PDF is a Gemini DSA coaching conversation. Extract every LeetCode problem discussed, deduplicate them, and add any missing problem folders under the appropriate existing pattern. Existing problems should not be duplicated.

Problems explicitly discussed in the PDF:

### Two Pointers / Related Pointer Techniques
- LeetCode 167: Two Sum II - Input Array Is Sorted
- LeetCode 11: Container With Most Water
- LeetCode 26: Remove Duplicates from Sorted Array
- LeetCode 15: 3Sum
- LeetCode 18: 4Sum
- LeetCode 75: Sort Colors / Dutch National Flag
- LeetCode 42: Trapping Rain Water
- LeetCode 457: Circular Array Loop
- LeetCode 143: Reorder List
- LeetCode 2511: Maximum Enemy Forts Captured

### Sliding Window
- LeetCode 643: Maximum Average Subarray I
- LeetCode 3: Longest Substring Without Repeating Characters
- LeetCode 209: Minimum Size Subarray Sum
- LeetCode 713: Subarray Product Less Than K
- LeetCode 424: Longest Repeating Character Replacement
- LeetCode 1004: Max Consecutive Ones III
- LeetCode 30: Substring with Concatenation of All Words

### Kadane / Dynamic Programming
- LeetCode 53: Maximum Subarray
- LeetCode 152: Maximum Product Subarray

### 1D Prefix Sum + Hash Map
- LeetCode 560: Subarray Sum Equals K
- LeetCode 974: Subarray Sums Divisible by K
- LeetCode 525: Contiguous Array

### 2D Prefix Sum / Matrix Prefix Techniques
- LeetCode 304: Range Sum Query 2D - Immutable
- LeetCode 1074: Number of Submatrices That Sum to Target

### Additional problem appearing in the coaching discussion
- LeetCode 581: Shortest Unsorted Continuous Subarray

Some of these already exist in the repository. Search by slug before creating anything.

## Missing Problems Expected To Need Adding

At minimum, check whether these exist; add only if absent:
- `11.container-with-most-water` under `01-two-pointers`
- `42.trapping-rain-water` under `01-two-pointers`
- `2511.maximum-enemy-forts-captured` under `01-two-pointers`
- `643.maximum-average-subarray-i` under `03-sliding-window`
- `304.range-sum-query-2d-immutable` under `05-prefix-sum`
- `1074.number-of-submatrices-that-sum-to-target` under `05-prefix-sum`

Folder names should omit the numeric LeetCode prefix, matching the current repository convention:
`container-with-most-water`, `trapping-rain-water`, etc.

## How To Add Missing Problems

For each missing LeetCode problem:
1. Use LeetCode MCP `get_problem` for the slug to fetch title, description, examples, constraints, and metadata.
2. Write `problem.md` directly into the correct pattern/problem folder.
3. Query the user's submissions with `get_all_submissions(questionSlug=<slug>)`.
4. Select accepted C++ submissions from 2026 if present. Preserve multiple accepted approaches.
5. Fetch exact code with `get_problem_submission_report`.
6. Write exact source into `approach-01.cpp`, `approach-02.cpp`, etc., preserving original comments. Do not invent or add restoration comments.
7. If no accepted submission exists, create only `problem.md` and do not invent a solution file.

## Validation

After editing:
- Verify there is exactly one folder per problem within each pattern.
- Verify no `leetcode-problems` folder or generator script is created.
- Verify every problem folder has `problem.md`.
- Verify LeetCode solution files retain correct `@lc` markers.
- Verify no artificial `Restored from...` comments remain.
- Verify the current user edits were not overwritten blindly.
- Use `get_errors` on touched files, but remember standalone LeetCode files may show missing standard-library/include diagnostics because LeetCode injects headers.
- Do not commit changes unless explicitly requested.
