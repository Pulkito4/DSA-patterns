/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:

    // int findMax(vector<int> arr){
    //     int maxVal = 0;
    //     for (int val : arr) {
    //         if (val > maxVal) {
    //             maxVal = val;
    //         }
    //     }
    //     return maxVal;
    // }

    int characterReplacement(string s, int k) {
        int n = s.size();
        if(n==0){
            return 0;
        } 
        int low=0;
        int res = 0;
        int maxCnt = 0;
        vector<int> freq(256,0);
        for(int high =0;high<n;high++){
            freq[s[high]]++;
            // int maxCnt = findMax(freq);
            maxCnt = max(maxCnt , freq[s[high]]);
            int len = high -low+1;
            int diff = len-maxCnt;
            // while(diff>k){
            //     freq[s[low]]--;
            //     low++;
            //     len = high-low+1;
            //     diff = len - maxCnt;
            // }
            if(diff>k){
                freq[s[low]]--;
                low++;
                diff = len - maxCnt;
            }


            len = high-low+1;
            res = max(res, len);
        }
        return res;
    }
};
// @lc code=end
