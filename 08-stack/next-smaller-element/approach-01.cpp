class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        st.push(arr[n - 1]);
        // for the rightmost element no element to right to check for
        res[n - 1] = -1;
        // traverse the loop right to left as opposed to left to right in prev greaters/smaller ques
        for (int i = n - 2; i >= 0; i--) {
            // keep popping till we find
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            // empty stack means nothing on right is smaller so ans is -1 and push current element
            if (st.empty()) {
                res[i] = -1;
            } else {
                res[i] = st.top();
            }
            st.push(arr[i]);
        }
        return res;
    }
};
