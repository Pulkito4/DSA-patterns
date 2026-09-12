/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    bool contains(vector<int>& current, vector<int>& required) {
        for (int i = 0; i < 256; i++) if (current[i] < required[i]) return false;
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> current(256, 0), required(256, 0);
        for (char c : t) required[c]++;
        int left = 0, best = INT_MAX, start = 0;
        for (int right = 0; right < s.size(); right++) {
            current[s[right]]++;
            while (contains(current, required)) {
                if (right - left + 1 < best) {
                    best = right - left + 1;
                    start = left;
                }
                current[s[left++]]--;
            }
        }
        return best == INT_MAX ? "" : s.substr(start, best);
    }
};
// @lc code=end
