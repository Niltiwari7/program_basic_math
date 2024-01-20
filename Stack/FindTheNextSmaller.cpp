// Sum of Subarray Minimums

class Solution {
public:
    typedef long long ll;

    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                result[i] = n;
            } else {
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return result;
    }

    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                result[i] = -1;
            } else {
                while (!st.empty() && arr[st.top()] > arr[i]) {
                    st.pop();
                }
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return result;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        long long sum = 0;
        int M = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            ll ls = i - NSL[i];
            ll rs = NSR[i] - i;

            ll totalWays = ls * rs;

            ll totalSum = arr[i] * totalWays;
            sum = (sum + totalSum) % M;
        }
        return static_cast<int>(sum);
    }
};
