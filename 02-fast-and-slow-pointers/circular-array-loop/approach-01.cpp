/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 */

// @lc code=start
class Solution {
public:
    int getNext(int i, vector<int>& nums) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int slow = i, fast = i;
            while (nums[i] * nums[fast] > 0 && nums[i] * nums[getNext(fast, nums)] > 0) {
                slow = getNext(slow, nums);
                fast = getNext(getNext(fast, nums), nums);
                if (slow == fast) {
                    if (slow == getNext(slow, nums)) break;
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
