class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> ans(n, 0);

        stack<pair<int, int>> st;

        for (int i = n - 1; i >= 0; i--) {

            // Remove temperatures that are <= current
            while (!st.empty() && st.top().first <= temperatures[i]) {
                st.pop();
            }

            // Top is the next warmer day
            if (!st.empty()) {
                ans[i] = st.top().second - i;
            }

            // Store {temperature, index}
            st.push({temperatures[i], i});
        }

        return ans;
    }
};