/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.length();
        vector<int> pattern(256, 0), window(256, 0), result;
        for (int i = 0; i < k; i++) {
            pattern[p[i]]++;
            window[s[i]]++;
        }
        if (window == pattern) result.push_back(0);
        for (int right = k; right < s.length(); right++) {
            window[s[right]]++;
            window[s[right - k]]--;
            if (window == pattern) result.push_back(right - k + 1);
        }
        return result;
    }
};
// @lc code=end
