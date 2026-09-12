/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution {
public:

    int maxKadane(vector<int>& nums, int n){
        int ans = nums[0];
        int maxSum = nums[0];
        for(int i =1;i<n;i++){
            maxSum = max(nums[i], maxSum+nums[i]);
            ans = max(maxSum,ans);
        }
        return ans;
    }
    
    int minKadane(vector<int>& nums, int n){
        int ans = nums[0];
        int minSum = nums[0];
        for(int i =1;i<n;i++){
            minSum = min(nums[i], minSum+nums[i]);
            ans = min(minSum,ans);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int arrSum=0;
        for(int i =0;i<n;i++){
            arrSum+=nums[i];
        }
        int maxSum = maxKadane(nums, n);
        int minSum = minKadane(nums, n);
        //edge case of all negative array, then minSum and arrSum will be same leading to 0 which will be incorrect as 0 wont be in that array
        if(maxSum<0){
            return maxSum;
        }
        int ans = max(maxSum, arrSum-minSum);
        return ans;
    }
};
// @lc code=end
