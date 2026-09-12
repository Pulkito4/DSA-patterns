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
        if (n <= 1) {
            return 0;
        }

        int maxSeen = INT_MIN, minSeen = INT_MAX;
        int left = -1, right = -1;
        for (int i = 0; i < n; i++) {
            maxSeen = max(maxSeen, nums[i]);
            if (nums[i] < maxSeen) {
                right = i;
            }

            int reverseIndex = n - 1 - i;
            minSeen = min(minSeen, nums[reverseIndex]);
            if (nums[reverseIndex] > minSeen) {
                left = reverseIndex;
            }
        }
        return (right == -1 || left == -1) ? 0 : right - left + 1;
    }
};
// @lc code=end
