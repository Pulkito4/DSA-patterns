/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
class Solution {
public:

    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size()-1;
        double curr_sum = 0;
        for(int i=0;i<k;i++){
            curr_sum+=nums[i];
        }
        double maxSum = curr_sum;

        for(int j=k; j<=n;j++){
            curr_sum = curr_sum + nums[j] - nums[j-k]; 
            maxSum= max(maxSum, curr_sum);
        }
        return maxSum/k;
    }
};
// @lc code=end