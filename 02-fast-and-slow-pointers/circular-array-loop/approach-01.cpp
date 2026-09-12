/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 */

// @lc code=start
class Solution {
public:
    int getNext(int i , vector<int>& nums) {
        int n = nums.size();
        // eg. nums[0] = -12 || n=5
        // i.e we want element at -2 index i.e 5-2 = 3 index
        // ((0-12)%5 + 5)%5 = (-2+ 5)%5 = 3%5 = 3
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // We are starting our search from index 'i'
            int slow = i;
            int fast = i;

            // fast checks its current spot, and the spot it's about to jump to
            while (nums[i] * nums[fast] > 0 &&
                   nums[i] * nums[getNext(fast, nums)] > 0) {

                // Move the pointers
                slow = getNext(slow, nums);
                fast = getNext(getNext(fast, nums), nums);

                // Did they collide?
                if (slow == fast) {
                    // Rule #3 Check: Is it a 1-element loop?
                    if (slow == getNext(slow, nums)) {
                        break; // Dead end. Stop searching this path.
                    }

                    return true; // We found a valid cycle!
                }
            }
        }
        return false; 
    }
};
// @lc code=end
