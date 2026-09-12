/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength= 0 ; 
        int n= s.length();
        if(n==0){
            return 0;
        }
        // 2nd // optimized approach
        unordered_map<char, int> char_map ; 
        int left = 0, right =0;
        while(right<n){
            if(char_map.count(s[right])){
                left = max(left , char_map[s[right]]+1);
            }
            char_map[s[right]] = right;
            int window = right-left+1;
            maxLength = max(maxLength,window);
            right++;
        }
        return maxLength;
    }

};
// @lc code=end
