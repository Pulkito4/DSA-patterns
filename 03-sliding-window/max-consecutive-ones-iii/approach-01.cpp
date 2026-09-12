/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int res = 0;
        int low = 0;
        int zeros = 0;
        for(int high =0;high<n;high++){
            if(nums[high]==0){
                zeros++;
            }
            while(zeros>k){
                if(nums[low]==0){
                    zeros--;
                }
                low++;
            }
            // diff <= k --> we can flip
            int len = high -low +1;
            res = max(res,len);
        }
        return res;
    }
};
// @lc code=end
