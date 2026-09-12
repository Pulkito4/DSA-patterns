/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> frequency(256, 0);
        int left = 0, result = 0, maxCount = 0;
        for (int right = 0; right < s.size(); right++) {
            maxCount = max(maxCount, ++frequency[s[right]]);
            if (right - left + 1 - maxCount > k) frequency[s[left++]]--;
            result = max(result, right - left + 1);
        }
        return result;
    }
};
// @lc code=end
