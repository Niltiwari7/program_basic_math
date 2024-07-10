class Solution {
public:
    // THIS WILL GIVE ME NEXT SMALLER ELEMENT FROM RIGHT SIDE
    vector<int> NextSmallerElementRight(vector<int> nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                result[i] = n;
            } else {
                while (!st.empty() && nums[st.top()] >= nums[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    result[i] = n;
                } else {
                    result[i] = st.top();
                }
            }
            st.push(i);
        }
        return result;
    }

    // THIS WILL GIVE ME NEXT SMALLER ELEMENT FROM LEFT SIDE
    vector<int> NextSmallerElementLeft(vector<int> nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                result[i] = -1;
            } else {
                while (!st.empty() && nums[st.top()] >= nums[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    result[i] = -1;
                } else {
                    result[i] = st.top();
                }
            }
            st.push(i);
        }
        return result;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSR = NextSmallerElementRight(heights);
        vector<int> NSL = NextSmallerElementLeft(heights);
        
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            int width = NSR[i] - NSL[i] - 1;
            int area = width * heights[i];
            ans = max(ans, area);
        }
        return ans;
    }
};
