/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> frequency;
        int left = 0, result = 0;
        for (int right = 0; right < fruits.size(); right++) {
            frequency[fruits[right]]++;
            while (frequency.size() > 2) {
                if (--frequency[fruits[left]] == 0) frequency.erase(fruits[left]);
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
// @lc code=end
