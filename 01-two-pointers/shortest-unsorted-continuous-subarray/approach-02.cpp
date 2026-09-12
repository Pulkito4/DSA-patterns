/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //optimized 2 pointer approach
        int n = nums.size();
        if(n<=1){
            return 0;
        }
        int max_seen= INT_MIN, min_seen= INT_MAX;
        int left = -1, right = -1;
        int i =0;
       for (int i = 0; i < n; i++) {
            // 1. Scan left-to-right to find the rightmost out-of-order element
            max_seen = max(max_seen, nums[i]);
            if (nums[i] < max_seen) {
                right = i;
            }
            
            // 2. Scan right-to-left to find the leftmost out-of-order element
            int reverse_i = n - 1 - i;
            min_seen = min(min_seen, nums[reverse_i]);
            if (nums[reverse_i] > min_seen) {
                left = reverse_i;
            }
        }
        return ((right==-1||left==-1)?0:(right-left+1));
    }
};
// @lc code=end
