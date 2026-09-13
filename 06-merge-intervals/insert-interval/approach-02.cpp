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

        // optimization 1 : by not using the sort function
        // since intervals is already sorted, we just need to find the correct
        // place to insert -> loop through the array O(n)
        int n = intervals.size();
        vector<vector<int>> res;
        bool inserted = false;

        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (newInterval[0] <= start && !inserted) {
                res.push_back(newInterval);
                inserted = true;
            }
            res.push_back({start, end});
        }
        // in case new interval has start greater then all existing
        if (!inserted) {
            res.push_back(newInterval);
            inserted = true;
        }

        n = res.size();
        // reuse intervals to save memory
        intervals.clear();
        // plain old merge intervals code ahead
        int start1 = res[0][0];
        int end1 = res[0][1];
        for (int i = 1; i < n; i++) {
            int start2 = res[i][0];
            int end2 = res[i][1];
            if (end1 >= start2) {
                start1 = start1;
                end1 = max(end1, end2);
                continue;
            }
            intervals.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }
        intervals.push_back({start1, end1});
        return intervals;
    }
};
// @lc code=end
