/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int sum = 0;
        int result = 0;
        // as empty array has sum=0 and 0%k = 0
        mpp[sum % k]++;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = ((sum % k) + k) % k;
            // if(rem<0){
            //     rem+=k;
            // }
            result += mpp[rem];

            mpp[rem]++;
        }
        return result;
    }
};
// @lc code=end
