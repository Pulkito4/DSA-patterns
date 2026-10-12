# Trapping Rain Water - Alternative Approach

## Approach 2: Monotonic Stack Approach

This problem can also be solved using a **Monotonic Decreasing Stack** by identifying bounded horizontal water layers between the current bar and the previous taller bars on the stack.

### Implementation & Notes
The complete implementation and solution code is located here:
👉 **[Monotonic Stack Approach (`approach-01.cpp`)](../../08-stack/trapping-rain-water/approach-01.cpp)**

### Complexity Summary
- **Time Complexity:** $\mathcal{O}(n)$ - each bar is pushed and popped from the stack at most once.
- **Space Complexity:** $\mathcal{O}(n)$ - stack stores indices of elevation bars.
