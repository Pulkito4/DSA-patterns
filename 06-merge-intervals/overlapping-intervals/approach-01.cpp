// User function template for C++

class Solution {
  public:
    bool isIntersect(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) {
            return false;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        for (int i = 1; i < n; i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if (end1 >= start2) {
                return true;
            }

            start1 = start2;
            end1 = end2;
        }

        return false;
    }
};
