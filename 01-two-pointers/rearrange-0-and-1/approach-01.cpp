// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int i=0;
        int n = arr.size();
        int j = n-1;
        while(i<j){
            while(arr[i]==0 && i<j){
                i++;
            }
            
            while(arr[j]==1&&i<j){
                j--;
            }
            if (i<j){
                swap(arr[i++],arr[j--]);
                
            }
        }
        
    }
};