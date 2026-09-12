/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zeroes = 0, ones = 0;
        int res = 0;
        unordered_map<int, int> diff_idx;
        for (int i = 0; i < n; i++) {
            nums[i] == 0 ? zeroes++ : ones++;
            int diff = zeroes - ones;
            if (diff == 0) {
                res = max(res, i + 1);
                continue;
            } else {
                if (diff_idx.find(diff) != diff_idx.end()) {
                    res = max(res, i - diff_idx[diff]);
                } else {
                    // we havent seen this difference in hashmap yet
                    diff_idx[diff] = i;
                }
            }
        }
        return res;
    }
};
// @lc code=end
