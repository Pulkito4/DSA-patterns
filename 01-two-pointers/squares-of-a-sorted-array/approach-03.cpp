/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // approach 2
        int n=nums.size();
        int i=0,j=n-1, pos =n-1;
        vector<int> ans(n);
        if (n==0) return ans;
        while(i<=j){
            // we could have also simply squared the nums array before the while loop
            // but this will be a little more less time consuming O(2n) -> O(n)
            int lsq = nums[i]*nums[i];
            int rsq = nums[j]*nums[j];
            if(lsq>rsq){
                ans[pos--]=lsq;
                i++;
            }else{
                ans[pos--]=rsq;
                j--;
            }
        }
        return ans;
    }
};
// @lc code=end
