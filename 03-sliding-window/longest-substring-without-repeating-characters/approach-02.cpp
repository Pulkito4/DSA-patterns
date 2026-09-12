/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int left = 0, result = 0;
        for (int right = 0; right < s.length(); right++) {
            if (lastSeen.count(s[right])) left = max(left, lastSeen[s[right]] + 1);
            lastSeen[s[right]] = right;
            result = max(result, right - left + 1);
        }
        return result;
    }
};
// @lc code=end
