#include <bits/stdc++.h>
class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int left = 0, right =left+k-1;
        int n = arr.size();
        int res = 0;
        int curr_sum = accumulate(arr.begin() + left, arr.begin() + right , 0);
        while(right<n){
            curr_sum +=arr[right];
            res = max(curr_sum,res);
            right++;
            curr_sum -= arr[left++];
        }
        return res;
    }
};