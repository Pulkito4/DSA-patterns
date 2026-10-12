The submissions you saw with half the code are using a **1-Pass Optimization**. They do exactly what you did, but they combine all three steps into a single loop using only one stack and no extra arrays.

Here is the intuition for how they eliminate the `prev_smaller` and `next_smaller` arrays entirely.

### The "Death" of an Element Reveals Everything

In your code, you push an element onto the stack, and later, when a shorter bar comes along, you pop it.

Think deeply about the exact moment an element is popped. Let's say the stack currently holds the indices for the heights `[1, 5, 6]`, and the current bar we are looking at has a height of `2`.

The `2` is going to force the `6` to pop. Why? Because `2` is smaller than `6`.

* **The Right Wall:** The element that *causes* the pop (the `2`) is mathematically guaranteed to be the **Next Smaller Element** for the `6`.

Now, look at what is sitting directly underneath the `6` in the stack right before it gets popped. It's the `5`.

* **The Left Wall:** Because of how a Monotonic Stack works, the element sitting directly below you in the stack is mathematically guaranteed to be your **Previous Smaller Element**.

### The 1-Pass Epiphany

You don't need to pre-calculate the walls. **The moment a bar is popped from the stack is the exact moment you calculate its maximum area.**

When the `6` is getting evicted by the `2`:

1. **Height:** The popped element itself (`6`).
2. **Right Wall:** The current index of the loop (the `2` that caused the eviction).
3. **Left Wall:** The new `st.top()` after popping the `6` (the `5` sitting beneath it).

You calculate `width = right_wall - left_wall - 1`, multiply it by the height, update `maxArea`, and *then* let the `6` vanish forever.

### The Lingering Survivors

If you run this 1-pass loop, what happens when you reach the end of the array?
Some bars might still be in the stack! (e.g., a bar that never found a smaller element to its right).

If a bar survives the whole loop, we just pop it manually at the end.

* **Its Right Wall:** Since it survived to the end, its right wall is simply the end of the array (`n`).
* **Its Left Wall:** Still just whatever is underneath it in the stack (or `-1` if the stack becomes empty).