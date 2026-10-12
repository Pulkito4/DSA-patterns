/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // The moment you hit a bar that is shorter than your current height,
        // your rectangle hits a brick wall.
        // If you want to calculate the largest possible rectangle that uses a
        // specific bar as its height, you need to know exactly where those
        // walls are on both sides.

        // we can find the left wall and right wall at any given index using the
        // next smaller element and previous smaller element then for any height
        // we can calculate the area of the rectange using :
        //  width = right wall - left wall - 1

        // OPTIMIZING TO SOLVE BOTH WALLS IN 1 pass only
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                // as soon as we get a smaller element on i that is the right
                // wall because we are moving from left to right
                int right = i;

                // save the index for which we are calculating the area
                int popped_rect = st.top();
                st.pop();
                // since this is a monotonic stack, the top element now will be
                // just
                // smaller that element at i  -> left wall if stack is empty
                // then left wall is the begining of the stack i.e left wall of
                // index 0 i.e -1
                int left = !st.empty() ? st.top() : -1;
                int width = right - left - 1;
                int area = heights[popped_rect] * width;
                maxArea = max(maxArea, area);
            }

            // store the index of current element in stack not the element
            // itself
            st.push(i);
        }

        // now there is a chance that st.top() was never greater than heights[i]
        // so elements will be piled up in stack but since we have reached the
        // end of array the right wall will be simply n
        while (!st.empty()) {
            int right = n;
            int target = st.top();
            st.pop();
            int left = !st.empty() ? st.top() : -1;
            int width = right - left - 1;
            int area = heights[target] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
// @lc code=end
