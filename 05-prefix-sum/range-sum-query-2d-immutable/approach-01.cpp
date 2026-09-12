/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
private:
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // padding original matrix with a row and col of 0s
        prefix = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

        // precomputing prefix sums
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // inclusion exclusion principle
                // rectangle = matrix element + above part + left part - double
                // counted corner
                prefix[r + 1][c + 1] = matrix[r][c] + prefix[r][c + 1] +
                                       prefix[r + 1][c] - prefix[r][c];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // Shift all original target coordinates by +1 because of our padding
        int r1 = row1 + 1;
        int c1 = col1 + 1;
        int r2 = row2 + 1;
        int c2 = col2 + 1;

        int rectangle = prefix[r2][c2];
        int left = prefix[r2][c1 - 1];
        int top = prefix[r1 - 1][c2];
        int top_left_corner = prefix[r1 - 1][c1 - 1];

        // top left corner is double counted i.e we need to add it one time
        // otherwise math is wrong
        return (rectangle - left - top + top_left_corner);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end