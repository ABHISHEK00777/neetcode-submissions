class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> pse(n);
        vector<int> nse(n);

        // -------------------------
        // 1. Previous Smaller
        // -------------------------

        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() &&
                   heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }

        // Clear stack
        while (!st.empty()) {
            st.pop();
        }

        // -------------------------
        // 2. Next Smaller
        // -------------------------

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() &&
                   heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }

        // -------------------------
        // 3. Calculate area
        // -------------------------

        int maxi = 0;

        for (int i = 0; i < n; i++) {

            int width = nse[i] - pse[i] - 1;

            int area = heights[i] * width;

            maxi = max(maxi, area);
        }

        return maxi;
    }
};