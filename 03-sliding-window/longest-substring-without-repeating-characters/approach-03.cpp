/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> frequency;
        int left = 0, result = 0;
        for (int right = 0; right < s.length(); right++) {
            frequency[s[right]]++;
            while (frequency.size() < right - left + 1) {
                if (--frequency[s[left]] == 0) frequency.erase(s[left]);
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
// @lc code=end
