/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // optimized approach using slow fast pointers
        // we can treat array as linked list by i = a[i] to do node movt
        // also we are already given that there will be duplicate i.e cycle
        // hence we dont need to check if cycle exists but essentially just 
        // find the starting point of the cycle
        int slow = 0;
        int fast =0;
        while(true){
            // since we dont need to check if cycle will exist or not we can just have true
            slow = nums[slow];
            fast=nums[fast];
            fast=nums[fast];
            if(slow==fast){
                //cycle detected
                slow = 0;
                while(slow!=fast){
                    slow = nums[slow];
                    fast=nums[fast];
                }
                // slow == fast => starting point reached
                return slow;
            }
        }
        return -1;
    }
};
// @lc code=end
