/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int n = height.size();
        int totalWater =0;
        int right = n-1;
        int maxLeft = height[left] , maxRight = height[right];
        while(left<right){
            if(maxLeft<=maxRight){
                left++;
                maxLeft = max(maxLeft, height[left]);
                totalWater+= maxLeft - height[left];
            }else{
                right--;
                maxRight = max(maxRight, height[right]);
                totalWater += maxRight - height[right];
            }
        }
        return totalWater;
    }
};
// @lc code=end