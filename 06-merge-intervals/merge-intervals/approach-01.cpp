/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        // O(nlogn)
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        // O(n)
        for (int i = 1; i < n; i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if (start2 <= end1) {
                start1 = start1;
                end1 = max(end1, end2);
                continue;
            }
            res.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }
        // loop ends but still last interval remains
        res.push_back({start1, end1});
        return res;
    }
};
// @lc code=end
