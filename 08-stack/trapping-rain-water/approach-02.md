# Trapping Rain Water - Alternative Approach

## Approach 2: Two Pointers Approach

This problem can also be solved optimally using the **Two Pointers** technique with $\mathcal{O}(1)$ auxiliary space and $\mathcal{O}(n)$ time complexity.

### Implementation & Notes
The complete implementation and solution code is located here:
👉 **[Two Pointers Approach (`approach-01.cpp`)](../../01-two-pointers/trapping-rain-water/approach-01.cpp)**

### Complexity Summary
- **Time Complexity:** $\mathcal{O}(n)$ - single pass from both ends converging to the center.
- **Space Complexity:** $\mathcal{O}(1)$ - only requires two boundary pointers and two prefix/suffix max variables.
