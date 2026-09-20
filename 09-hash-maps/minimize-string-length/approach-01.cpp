/*
 * @lc app=leetcode id=2825 lang=cpp
 *
 * [2825] Minimize String Length
 */

// @lc code=start
class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> st;
        for(int i=0;i<s.length();i++){
            st.insert(s[i]);
        }
        return st.size();
    }
};
// @lc code=end
