/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].size();
        int wordCount = words.size();
        unordered_map<string, int> required;
        for (string& word : words) required[word]++;
        vector<int> result;

        for (int offset = 0; offset < wordLength; offset++) {
            unordered_map<string, int> frequency;
            int left = offset, validWords = 0;
            for (int right = offset; right + wordLength <= s.size(); right += wordLength) {
                string word = s.substr(right, wordLength);
                if (!required.count(word)) {
                    frequency.clear();
                    validWords = 0;
                    left = right + wordLength;
                    continue;
                }
                frequency[word]++;
                validWords++;
                while (frequency[word] > required[word]) {
                    frequency[s.substr(left, wordLength)]--;
                    left += wordLength;
                    validWords--;
                }
                if (validWords == wordCount) {
                    result.push_back(left);
                    frequency[s.substr(left, wordLength)]--;
                    left += wordLength;
                    validWords--;
                }
            }
        }
        return result;
    }
};
// @lc code=end
