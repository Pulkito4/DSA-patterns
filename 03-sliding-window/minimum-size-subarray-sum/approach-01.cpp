/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;
        int left = 0, currentSum = 0;
        for (int right = 0; right < nums.size(); right++) {
            currentSum += nums[right];
            while (currentSum >= target) {
                minLength = min(minLength, right - left + 1);
                currentSum -= nums[left++];
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};
// @lc code=end
