/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;

        // circular array ->  we can simply handle the circle by making another
        // array(physically or virtually) twice the original array eg : [1 2 1]
        // -> [1 2 1   1 2 1] so now we can treat it like a normal next greater
        // element question with the condition that the 2nd half is a ghost i.e
        // doesnt really exist and we will simply use it to populate our stack
        // and pushing to answer will happen in the real part of the array but
        // to avoid creating a 2n size array we can think of it as a virtual
        // array and to handle it we can simply use modulo (%) operator to deal
        // with indexes

        for (int i = 2 * n - 1; i >= 0; i--) {
            // eg : 2 % 3 = 2  && 5%3 = 2
            int actual_idx = i % n;
            // pop untill we have the greater element
            while (!st.empty() && st.top() <= nums[actual_idx]) {
                st.pop();
            }
            // the ghost part to just fill the stack, we store ans only in real
            // part
            if (i < n) {
                if (st.empty()) {
                    // When i is less than n, i and actual_idx are
                    // mathematically identical. If i = 2, then 2 % 3 = 2.
                    // (actual_idx is 2) If i = 1, then 1 % 3 = 1. (actual_idx
                    // is 1) so we cacn use res[i] or res[actual_idx], it would
                    // mean the same
                    res[actual_idx] = -1;
                } else {
                    res[actual_idx] = st.top();
                }
            }
            // can't use i here as in begining it i would start in the
            // ghot part and nums array cant cater to that for eg n=3, then i=5
            // for 1st iteration and nums[5] is invalid access
            st.push(nums[actual_idx]);
        }

        return res;
    }
};
// @lc code=end
