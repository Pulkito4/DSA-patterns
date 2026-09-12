/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        vector<int> ans;

        if (n == 0) {
            ans.push_back(-1);
            return ans;
        }
        if (n == 1) {
            ans.push_back(nums[0] * nums[0]);
            return ans;
        }

        while (i < n && nums[i] < 0) i++;
        for (auto& num : nums) num *= num;
        int j = i;
        i--;
        while (i > -1 && j < n) {
            if (nums[i] < nums[j]) ans.push_back(nums[i--]);
            else if (nums[i] > nums[j]) ans.push_back(nums[j++]);
            else {
                ans.push_back(nums[i--]);
                ans.push_back(nums[j++]);
            }
        }
        while (i > -1) ans.push_back(nums[i--]);
        while (j < n) ans.push_back(nums[j++]);
        return ans;
    }
};
// @lc code=end
