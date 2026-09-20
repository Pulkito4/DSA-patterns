class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        st.push(arr[0]);
        // for the 1st element there is no element on left side
        res[0] = -1;
        for (int i = 1; i < n; i++) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            // if the stack is empty means no element on left was greater
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
