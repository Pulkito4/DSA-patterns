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

        // optimization 2 approach: using prefix sum to calculate the sum of
        // each row then applying the LC:560, prefix sum with hashmap on the
        // columns/vertically O(rows^2 * cols^2) -> O(rows^2 * cols)

        // STEP 1: 1D Prefix Sum for each row (modifying matrix in-place to save
        // space)
        for (int r = 0; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                matrix[r][c] += matrix[r][c - 1];
            }
        }

        // STEP 2: Fix the left and right walls/cols and iterate over them
        for (int left = 0; left < cols; left++) {
            for (int right = left; right < cols; right++) {

                // STEP 3: with fixed walls we need hashmap for (sum-k) dowm the
                // rows
                int curr_sum = 0;
                unordered_map<int, int> mp;
                mp[0] = 1; // as empthy sub array has sum == 0

                for (int r = 0; r < rows; r++) {

                    // Extract the row's sum trapped between our walls
                    int row_sum = matrix[r][right];
                    if (left > 0) {
                        row_sum -= matrix[r][left - 1];
                    }

                    curr_sum += row_sum;
                    int ques = curr_sum - target;
                    int freq = mp[ques];
                    res += freq;
                    mp[curr_sum]++;
                }
            }
        }

        return res;
    }
};
// @lc code=end