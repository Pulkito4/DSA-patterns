#include <bits/stdc++.h>

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        if(n==0){
            return -1;
        }
        int res = -1;
        int left = 0;
        unordered_map<char,int> hash_map;
        for(int right=0;right<n;right++){
            hash_map[s[right]]++;
            
            while(hash_map.size()>k){
                hash_map[s[left]]--;
                if(hash_map[s[left]]==0){
                    hash_map.erase(s[left]);
                }
                left++;
            }
            
            if(hash_map.size()==k){
                int len = right-left+1;
                res = max(res,len);
            }
            
        }
        
        return res;
    }
};