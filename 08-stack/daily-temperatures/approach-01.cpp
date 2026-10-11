/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // this essentially is the next greater element question only
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n);

        // since we want the no of days-> we store the index of element in stack
        // instead of the actual value
        for (int i = n - 1; i >= 0; i--) {
            // while the top of stack is not a warmer day we pop
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (st.empty()) {
                res[i] = 0;
                // If not empty, the top of the stack is the INDEX of our next
                // warmer day
            } else {
                // so basically 
                // dist = index_of_warmer_day - current index
                res[i] = st.top() - i;
            }
            st.push(i);
        }

        return res;
    }
};
// @lc code=end
