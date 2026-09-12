/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        if (k > s2.length()) return false;
        vector<int> first(256, 0), window(256, 0);
        for (int i = 0; i < k; i++) {
            first[s1[i]]++;
            window[s2[i]]++;
        }
        if (first == window) return true;
        for (int right = k; right < s2.length(); right++) {
            window[s2[right]]++;
            window[s2[right - k]]--;
            if (first == window) return true;
        }
        return false;
    }
};
// @lc code=end
