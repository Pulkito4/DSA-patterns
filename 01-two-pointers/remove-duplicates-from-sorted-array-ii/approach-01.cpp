/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }

        int i = 1;
        int j = 1;
        int cnt = 1;
        while (j < n) {
            if (nums[j] == nums[j - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            if (cnt <= 2) {
                nums[i++] = nums[j];
            }
            j++;
        }
        return i;
    }
};
// @lc code=end
