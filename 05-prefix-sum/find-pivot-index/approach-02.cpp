/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (int value : nums) total += value;
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            int right = total - left - nums[i];
            if (left == right) return i;
            left += nums[i];
        }
        return -1;
    }
};
// @lc code=end
