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

        // Padding with an extra row and column of 0s
        prefix = vector<vector<int>>(
            rows + 1,
            vector<int>(cols + 1, 0)
        );

        // Precomputing prefix sums
        for (int r = 0; r < rows; r++) {

            // Running sum of the current row
            int rowPrefix = 0;

            for (int c = 0; c < cols; c++) {

                // Add current element to current row's running sum
                rowPrefix += matrix[r][c];

                // Sum of everything above this position
                int above = prefix[r][c + 1];

                // Current row's sum + everything above
                prefix[r + 1][c + 1] = rowPrefix + above;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        // Bottom-right corner of target rectangle
        int rectangle = prefix[row2 + 1][col2 + 1];

        // Remove everything to the left
        int left = prefix[row2 + 1][col1];

        // Remove everything above
        int top = prefix[row1][col2 + 1];

        // Add back top-left because it was subtracted twice
        int topLeft = prefix[row1][col1];

        return rectangle - left - top + topLeft;
    }
};
// @lc code=end