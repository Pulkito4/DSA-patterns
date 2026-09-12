/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int j = 1;
        int count = 1;

        while (j < n) {
            if (nums[j] == nums[j - 1]) {
                j++;
                continue;
            }
            nums[++i] = nums[j++];
            count++;
        }
        return count;
    }
};
// @lc code=end
