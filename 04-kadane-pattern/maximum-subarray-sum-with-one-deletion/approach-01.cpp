/*
 * @lc app=leetcode id=1186 lang=cpp
 *
 * [1186] Maximum Subarray Sum with One Deletion
 */

// @lc code=start
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDeletion = arr[0], oneDeletion = INT_MIN, result = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            int previousNoDeletion = noDeletion;
            int previousOneDeletion = oneDeletion;
            noDeletion = max(previousNoDeletion + arr[i], arr[i]);
            int deletedCurrent = previousNoDeletion;
            int extendedDeleted = previousOneDeletion == INT_MIN ? arr[i] : previousOneDeletion + arr[i];
            oneDeletion = max(deletedCurrent, extendedDeleted);
            result = max(result, max(noDeletion, oneDeletion));
        }
        return result;
    }
};
// @lc code=end
