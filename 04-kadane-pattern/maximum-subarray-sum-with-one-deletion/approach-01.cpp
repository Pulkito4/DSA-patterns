/*
 * @lc app=leetcode id=1186 lang=cpp
 *
 * [1186] Maximum Subarray Sum with One Deletion
 */

// @lc code=start
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int nodelete=arr[0];
        int onedelete=INT_MIN;
        int ans = arr[0];
        for(int i =1;i<n;i++){
            int prevnodelete = nodelete; 
            int prevonedelete =onedelete;
            // in case of no deletion there are 2 possibilities 
            // either take the current number or simply start array from currnt index
            int v1 = nodelete + arr[i];
            int v2 = arr[i];
            nodelete = max(v1,v2);

            // now incase of 1 element deletion
            // either we already have a subarray with one element deleted so only option is to add the current element => onedelete + arr[i]
            // or uptill now there was no deletion in a subarray and we want to delete the current element => simply have the best sub array with nodelete ending and skip the current element 
            // then the onedelete best ending will be max of these two
            
            //adding this check because for i=0 one delete is garbage value or in our case INT_MIN
            if(prevonedelete==INT_MIN){
                v2 = arr[i];
            }else{
                v2 = prevonedelete + arr[i];
            }

            onedelete= max(prevnodelete, v2);
            ans = max(ans, max(onedelete,nodelete));
        }
        return ans;
    }
};
// @lc code=end
