class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> res(n);
        st.push(arr[0]);
        // for 1st element there is no element on left
        res[0] = -1;
        for (int i = 1; i < n; i++) {
            // keep popping untill we encounter -1 or element smaller that arr[i]
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                // empty stack means no smaller element for current arr[i] on leftside
                res[i] = -1;
            } else {
                res[i] = st.top();
            }
            // either way push the current arr[i] so its considered by next element
            st.push(arr[i]);
        }
        return res;
    }
};
