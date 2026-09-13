/*
 * @lc app=leetcode id=1028 lang=cpp
 *
 * [1028] Interval List Intersections
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int n = firstList.size();
        int m = secondList.size();

        if (n == 0 || m == 0) {
            return res;
        }
        int i = 0, j = 0;
        while (i < n && j < m) {
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            // approach 2 to simply the if else blocks
            // Check if the two intervals overlap 
            // the following if condition will hold true if there is any overlap ever
            if (start1 <= end2 && start2 <= end1) {

                int s = max(start1, start2);
                int e = min(end1, end2);

                res.push_back({s, e});
            }

            // now update i or j based on whichever range finished first
            if(end1<=end2){
                // list1 slot over, so we check its next interval overlap with list2 current slot
                i++;
            }else{
                j++;
            }
        }

        return res;
    }
};
// @lc code=end
