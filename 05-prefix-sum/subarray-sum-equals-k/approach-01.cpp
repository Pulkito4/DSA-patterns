/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum=0;
        unordered_map<int,int> mp;
        int res = 0;
        mp[0]=1; // as empthy sub array has sum == 0
        for(int i =0;i<n;i++){
            sum+=nums[i];
            int ques = sum-k;
            int freq = mp[ques];
            res+=freq;
            mp[sum]++;
        }
        return res;
    }
};
// @lc code=end
