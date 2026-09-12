/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return 0;
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        int left = -1, right = -1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != sorted[i]) {
                left = i;
                break;
            }
        }
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] != sorted[i]) {
                right = i;
                break;
            }
        }
        return (right == -1 || left == -1) ? 0 : right - left + 1;
    }
};
// @lc code=end
