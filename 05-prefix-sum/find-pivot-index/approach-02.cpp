/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sumArr = 0;
        for (int i = 0; i < n; i++) {
            sumArr += nums[i];
        }
        int left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            // left += nums[i - 1];
            right = sumArr - left - nums[i];
            if (left == right) {
                return i;
            }
            left+=nums[i];
        }
        return -1;
    }
};
// @lc code=end
