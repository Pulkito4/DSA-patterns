/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        frequency[0]++;
        int sum = 0, result = 0;
        for (int value : nums) {
            sum += value;
            int remainder = ((sum % k) + k) % k;
            if (frequency.find(remainder) != frequency.end()) result += frequency[remainder];
            frequency[remainder]++;
        }
        return result;
    }
};
// @lc code=end
