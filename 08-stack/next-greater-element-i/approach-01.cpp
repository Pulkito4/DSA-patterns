/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        // using a map to store next greater element of each item in nums 2
        // we can then use this for O(1) lookup for nums1
        unordered_map<int, int> mp;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                // eg. [4 1 2 ] -> mp[nums2[2]] -> mp[2]=-1
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};
// @lc code=end
