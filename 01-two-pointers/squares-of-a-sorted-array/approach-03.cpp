/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1, pos = n - 1;
        vector<int> ans(n);
        if (n == 0) {
            return ans;
        }
        while (i <= j) {
            int leftSquare = nums[i] * nums[i];
            int rightSquare = nums[j] * nums[j];
            if (leftSquare > rightSquare) {
                ans[pos--] = leftSquare;
                i++;
            } else {
                ans[pos--] = rightSquare;
                j--;
            }
        }
        return ans;
    }
};
// @lc code=end
