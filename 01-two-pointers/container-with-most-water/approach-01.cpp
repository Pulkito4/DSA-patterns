/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0 ;
        int i=0,j=height.size() -1;
        while (i<j){
            int width = j-i;
            int area = width * min(height[i], height[j]);
            res = max(area,res);
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
        }
        return res;
    }
};
// @lc code=end