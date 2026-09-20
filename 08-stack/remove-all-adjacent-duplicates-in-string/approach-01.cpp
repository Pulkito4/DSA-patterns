/*
 * @lc app=leetcode id=1128 lang=cpp
 *
 * [1128] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string res;
        stack<char> st;
        for(int i=0;i<n;i++){
            char c = s[i];
            if(st.empty()==false && st.top()==c){
                st.pop();
            }else{
                st.push(c);
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
       reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end
