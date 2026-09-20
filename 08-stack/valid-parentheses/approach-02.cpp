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
        // a bit more standard and optmized approach
        for (char c : s) {
            // if it is a opening bracket push it
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                // it is a closing bracket
                if (st.empty()) {
                    // if the stack is empty then closing bracket being the 1st
                    // element is invalid
                    return false;
                } else {
                    // basically the opposity of what we checked in the 1st approach
                    // if the closing bracket doesnt match the most recently opened scope then is it invalid -> eg> (  ]  
                    if ((c == ')' && st.top() != '(') ||
                        (c == ']' && st.top() != '[') ||
                        (c == '}' && st.top() != '{')) {
                        return false;
                    }
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};
// @lc code=end
