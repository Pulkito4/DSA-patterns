/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < n; i++) {
            char c = s[i];
            if (st.empty() == false && ((st.top() == '(' && c == ')') ||
                                        (st.top() == '[' && c == ']') ||
                                        (st.top() == '{' && c == '}'))) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
// @lc code=end
