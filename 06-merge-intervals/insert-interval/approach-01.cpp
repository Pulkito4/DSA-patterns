/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        for (int i = 1; i < n; i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            if (end1 >= start2) {
                start1 = start1;
                end1 = max(end1, end2);
                continue;
            }
            res.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }
        res.push_back({start1, end1});
        return res;
    }
};
// @lc code=end
