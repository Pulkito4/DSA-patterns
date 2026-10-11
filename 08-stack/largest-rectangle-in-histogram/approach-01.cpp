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

        int n = heights.size();
        stack<int> st;
        // arrays to store right and left wall for each index
        vector<int> next_smaller(n), prev_smaller(n);

        // STEP 1: find prev smaller element for all index
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            // if stack is empty then no smaller element on left
            // i.e wall is the start of array / end of array from left
            if (st.empty()) {
                prev_smaller[i] = -1;
            } else {
                prev_smaller[i] = st.top();
            }
            // store the index of current element in stack not the element
            // itself
            st.push(i);
        }

        // EMPTY THE STACK FOR REUSE
        while (!st.empty()) {
            st.pop();
        }

        // STEP 2 : find next smaller element for each index
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            // if stack is empty then no smaller element on the right
            // i.e the right wall is the end of the array => n (because index
            // starts with 0)
            if (st.empty()) {
                next_smaller[i] = n;
            } else {
                next_smaller[i] = st.top();
            }
            st.push(i);
        }

        int maxArea = 0;
        // STEP 3 : calculate area for each height checking its left and right
        // wall each time
        for (int i = 0; i < n; i++) {
            int width = next_smaller[i] - prev_smaller[i] - 1;
            int area = heights[i] * width;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};
// @lc code=end
