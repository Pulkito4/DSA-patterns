/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // step 1: find the longest prefix match 
        // i.e look for the break point/dip starting from the back
        int index = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
        // EDGE CASE
        // if index is still -1 that means no break point
        // i,e it is the largest permutation so circle back to the sorted array
        if(index==-1){
            reverse(nums.begin(), nums.end());
            return;
        }

        //step 2: find the minimum number greater than arr[i]
        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[index], nums[i]);
                break;
            }
        }


        // step 3: reverse/ sort the remaining array beyond the break point
        reverse(nums.begin()+index+1, nums.end());
    }
};
// @lc code=end
