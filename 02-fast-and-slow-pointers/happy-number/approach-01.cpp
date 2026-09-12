/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    int sumsq(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            sum += digit * digit;
        }
        return sum;
    }

    bool isHappy(int n) {
        if (n == 1) return true;
        int slow = n, fast = n;
        while (fast != 1) {
            slow = sumsq(slow);
            fast = sumsq(sumsq(fast));
            if (slow == fast && slow != 1) return false;
        }
        return true;
    }
};
// @lc code=end
