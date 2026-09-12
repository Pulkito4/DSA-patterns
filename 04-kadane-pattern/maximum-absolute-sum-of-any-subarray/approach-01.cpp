/*
 * @lc app=leetcode id=1749 lang=cpp
 *
 * [1749] Maximum Absolute Sum of Any Subarray
 */

// @lc code=start
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEnding = nums[0], minEnding = nums[0], result = abs(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            maxEnding = max(nums[i], maxEnding + nums[i]);
            minEnding = min(nums[i], minEnding + nums[i]);
            result = max(result, max(abs(maxEnding), abs(minEnding)));
        }
        return result;
    }
};
// @lc code=end
