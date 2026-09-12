/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        frequency[0] = 1;
        int sum = 0, result = 0;
        for (int value : nums) {
            sum += value;
            result += frequency[sum - k];
            frequency[sum]++;
        }
        return result;
    }
};
// @lc code=end
