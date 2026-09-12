/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, currentMax = nums[0], maxSum = nums[0];
        int currentMin = nums[0], minSum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
            if (i > 0) {
                currentMax = max(nums[i], currentMax + nums[i]);
                maxSum = max(maxSum, currentMax);
                currentMin = min(nums[i], currentMin + nums[i]);
                minSum = min(minSum, currentMin);
            }
        }
        if (maxSum < 0) return maxSum;
        return max(maxSum, total - minSum);
    }
};
// @lc code=end
