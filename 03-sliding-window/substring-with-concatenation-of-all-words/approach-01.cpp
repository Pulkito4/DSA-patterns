/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int wordLen = words[0].size();
        int k = words.size();
        vector<int> res;

        // store all the words in a hashmap
        unordered_map<string, int> mp;
        for (int i = 0; i < k; i++) {
            mp[words[i]]++;
        }

        for (int i = 0; i < wordLen; i++) {
            unordered_map<string, int> freq;
            int low = i, high = i;
            int validWordCount =0;
            while (high+wordLen <= n) {
                string currword = s.substr(high, wordLen);
                high += wordLen;

                //if substr word is garbage, move to next starting point
                if (mp.count(currword) == 0) {
                    low = high;
                    freq.clear();
                    validWordCount =0;
                    continue;
                }
                //valid word i.e present in all words map
                else {
                    freq[currword]++;
                    validWordCount++;
                    // in case our substr word has more entries than original word list
                    while (freq[currword] > mp[currword]) {
                        freq[s.substr(low,wordLen)]--;
                        low += wordLen;
                        validWordCount--; // word is valid but of no use to us 
                    }

                    // if no. of valid words = total words in original map/words arru
                    if(validWordCount==k){
                        res.push_back(low);
                        // after using shrink window to move ahead
                        freq[s.substr(low,wordLen)]--;
                        validWordCount--;
                        low+=wordLen;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
