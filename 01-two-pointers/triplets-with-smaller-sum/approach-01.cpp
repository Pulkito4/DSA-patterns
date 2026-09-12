class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        long long count=0;
        sort(arr, arr+n);
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                long long tempSum = arr[i]+arr[j]+arr[k];
                if(tempSum>=sum){
                    k--;
                }else{
                    count+=(k-j);
                    j++;
                }
            }
        }
        return count;
    }
};