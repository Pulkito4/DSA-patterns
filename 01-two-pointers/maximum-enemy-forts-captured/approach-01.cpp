/*
 * @lc app=leetcode id=2511 lang=cpp
 *
 * [2511] Maximum Enemy Forts Captured
 */

// @lc code=start
class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        int maxForts = 0;
        int anchor = -1;

        for (int i = 0; i < n; i++) {
            if (forts[i] == 0) continue;

            if (anchor != -1 && forts[anchor] != forts[i]) {
                int len = i - anchor - 1;
                maxForts = max(maxForts, len);
            }
            anchor = i;
        }
        return maxForts;
    }
};
// @lc code=end