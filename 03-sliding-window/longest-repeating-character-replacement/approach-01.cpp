/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:
    int findMax(vector<int> values) {
        int result = 0;
        for (int value : values) result = max(result, value);
        return result;
    }

    int characterReplacement(string s, int k) {
        vector<int> frequency(256, 0);
        int left = 0, result = 0;
        for (int right = 0; right < s.size(); right++) {
            frequency[s[right]]++;
            int maxCount = findMax(frequency);
            while (right - left + 1 - maxCount > k) {
                frequency[s[left++]]--;
                maxCount = findMax(frequency);
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
// @lc code=end
