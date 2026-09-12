/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0], minProduct = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int first = maxProduct * nums[i];
            int second = minProduct * nums[i];
            maxProduct = max(first, max(second, nums[i]));
            minProduct = min(first, min(second, nums[i]));
            result = max(result, maxProduct);
        }
        return result;
    }
};
// @lc code=end
