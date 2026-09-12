/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
    string process(string& str) {
        int i = 0;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '#') {
                if (i > 0) {
                    i--;
                }
            } else {
                str[i++] = str[j];
            }
        }
        return str.substr(0, i);
    }

    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};
// @lc code=end
