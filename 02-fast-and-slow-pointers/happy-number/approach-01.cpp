/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:

    int sumsq(int n){
        int sum =0;
        while (n>0){
            int d = n%10;
            n=n/10;
            sum+= d*d;
        }
        return sum;
    }

    bool isHappy(int n) {
        if(n==1){
            return true;
        }
        int slow = n;
        int fast= n;
        while(fast!=1){
            slow = sumsq(slow);
            fast=sumsq(fast);
            fast=sumsq(fast);
            if(slow==fast && slow!=1){
                // cycle detected but not of 1
                // as we can also have a loop on 1 (100 -> 1*1 + 0*0 + 0*0 = 1)
                return false;
            }
            // could be a cycle but it will be of 1 self loop => fast=1
            // hence we can return true here but we will simple return it outside this block
        }
        // means fast =1 => happy
        return true;

    }
};
// @lc code=end
