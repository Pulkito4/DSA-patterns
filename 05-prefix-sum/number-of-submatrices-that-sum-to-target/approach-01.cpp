/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 */

// @lc code=start
class Solution {

public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        // optimization 1 approach: using prefix sum to calculate the sum of sub
        // matrices building this on LC:304 we will optimize the calculation of
        // sums and remove the nested summation loops to get the problem from
        // O(rows^3 * cols^3) -> O(rows^2 * cols^2)

        // padding with 0s to handle edge cases
        vector<vector<int>> prefix(rows + 1, vector<int>(cols + 1, 0));

        // calculating the prefix matrix
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                prefix[r + 1][c + 1] = matrix[r][c] + prefix[r][c + 1] +
                                       prefix[r + 1][c] - prefix[r][c];
            }
        }

        // starting with 1 as prefix matrix has 1 row and col padding of 0s
        // and since we wont refer to the og matrix we can loop till <=rows/cols
        for (int r1 = 1; r1 <= rows; r1++) {
            for (int c1 = 1; c1 <= cols; c1++) {

                for (int r2 = r1; r2 <= rows; r2++) {
                    for (int c2 = c1; c2 <= cols; c2++) {

                        int rectangle = prefix[r2][c2];
                        int left = prefix[r2][c1 - 1];
                        int top = prefix[r1 - 1][c2];
                        int top_left_corner = prefix[r1 - 1][c1 - 1];
                        int currsum = rectangle - left - top + top_left_corner;

                        if (currsum == target) {
                            res++;
                        }
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end