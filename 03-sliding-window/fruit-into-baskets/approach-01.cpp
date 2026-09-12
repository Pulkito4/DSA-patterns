/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n==0){
            return 0;
        }
        int low = 0;
        int max_fruits = 0;
        unordered_map<int,int> freq;
        for(int high=0;high<n;high++){
            freq[fruits[high]]++;
            // since 2 baskets => k=2
            while(freq.size()>2){
                freq[fruits[low]]--;
                if(freq[fruits[low]]==0){
                    freq.erase(fruits[low]);
                }
                low++;
            }
            int len = high-low+1;
            max_fruits=max(max_fruits,len);
        }
        return max_fruits;
    }
};
// @lc code=end
