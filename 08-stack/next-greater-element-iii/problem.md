# Next Greater Element III

- Problem ID: 556
- Difficulty: Medium
- Source: [https://leetcode.com/problems/next-greater-element-iii/description/](https://leetcode.com/problems/next-greater-element-iii/description/)

## Problem Description

<p>Given a positive integer <code>n</code>, find <em>the smallest integer which has exactly the same digits existing in the integer</em> <code>n</code> <em>and is greater in value than</em> <code>n</code>. If no such positive integer exists, return <code>-1</code>.</p>

<p><strong>Note</strong> that the returned integer should fit in <strong>32-bit integer</strong>, if there is a valid answer but it does not fit in <strong>32-bit integer</strong>, return <code>-1</code>.</p>

> **Note on Strategy:**  
> This problem directly reduces to finding the **Next Permutation** of the digits of `n`.
> See [`01-two-pointers/next-permutation`](../../01-two-pointers/next-permutation/problem.md) and its solution implementation in [`approach-01.cpp`](../../01-two-pointers/next-permutation/approach-01.cpp).
> After computing the next lexicographical permutation of the stringified digits, convert back to a number and verify it does not exceed the 32-bit signed integer limit (`INT_MAX` / $2^{31} - 1$). If it overflows or no permutation exists, return `-1`.

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 12
<strong>Output:</strong> 21
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 21
<strong>Output:</strong> -1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>
