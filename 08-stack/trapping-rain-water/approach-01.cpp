/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // APPROACH - USING MONOTONIC STACK
        // SIMILAR TO LC: 84 - largest area rectangle
        // we need to trap the water between a left and a right wall
        int n = height.size();
        stack<int> st; 
        int totalWater =0 ;

        for(int i =0;i<n;i++){
            // keep popping until we get height smaller than top of stack
            // i.e puddle formation possible as we see height greater than top of stack
            while(!st.empty() && height[st.top()]<=height[i]){
                // the index that triggered the pop is the right wall
                int right_wall = i;

                // element at top of stack is the index where puddle can be formed
                int bottom = st.top();
                st.pop();

                // now since it is a monotonic stack, after popping the element that we have on top is the left wall i.e value bigger that bottom 
                // if stack is empty after pop there is no left wall i.e water spills 
                // so we break out of the while loop
                if(st.empty()){
                    break;
                }
                int left_wall = st.top();
                int width = right_wall - left_wall - 1;
                int depth = min(height[right_wall], height[left_wall]) - height[bottom];
                int area = depth * width; 
                totalWater+=area;
            }
            st.push(i);
        }
        return totalWater;
    }
};
// @lc code=end
