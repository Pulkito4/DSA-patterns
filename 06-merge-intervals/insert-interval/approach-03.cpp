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

        // optimization 2 : insert the interval while merging only
        int n = intervals.size();
        vector<vector<int>> res;
        int i =0;

        // divide the intervals into 3 loops
        // 1) before new interval
        // 2) merging with new interval
        // 3) after new interval
        
        // 1) before
        while(i<n && intervals[i][1]<newInterval[0]){
            res.push_back({intervals[i]});
            i++;
        }

        // 2) intervals overlapping with new interval
        // start shold be less than new interval ka end => merge them into the new interval
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(intervals[i][0], newInterval[0]);
            newInterval[1]=max(intervals[i][1], newInterval[1]);
            i++;
        }
        // now push the new merged interval
        res.push_back(newInterval);


        // 3) intervals after new interval
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
// @lc code=end
