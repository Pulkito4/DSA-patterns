/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIndex;
        int zeros = 0, ones = 0, result = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] == 0 ? zeros++ : ones++;
            int difference = zeros - ones;
            if (difference == 0) {
                result = max(result, i + 1);
            } else if (firstIndex.find(difference) != firstIndex.end()) {
                result = max(result, i - firstIndex[difference]);
            } else {
                firstIndex[difference] = i;
            }
        }
        return result;
    }
};
// @lc code=end
