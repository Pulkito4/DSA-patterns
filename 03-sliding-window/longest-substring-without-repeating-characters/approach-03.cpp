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
        // another approach, we can also find the size of the map and compare with window
        // if the size of map (i.e no of unique elements in the map) = size of window
        // => all characters in window are unique
        int maxLength= 0 ; 
        int n= s.length();
        if(n==0){
            return 0;
        }
        unordered_map<char, int> char_map ; 
        int left = 0;
        for(int right = 0; right<n;right++){
            char_map[s[right]]++;
            int k = right-left+1;
            if(char_map.size()<k){
                //means duplicates in the map
                char_map[s[left]]--;
                if(char_map[s[left]]==0){
                    char_map.erase(s[left]);
                }
                left++;
                k = right-left+1;
            }
            int window = right-left+1;
            maxLength = max(maxLength,window);
        }
        return maxLength;
    }

};
// @lc code=end
