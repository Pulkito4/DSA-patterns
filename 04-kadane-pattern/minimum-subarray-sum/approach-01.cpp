class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        int n = a.size();
        int minSum=a[0];
        int best_choice=a[0];
        for(int i=1;i<n;i++){
            int v1 = best_choice+a[i];
            int v2= a[i];
            best_choice = min(v1,v2);
            minSum = min(best_choice, minSum);
        }
        return minSum;
    }
};