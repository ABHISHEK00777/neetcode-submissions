class Solution {
   public:
    int solve(int i, vector<int>& cost, vector<int>& dp) {
        // Already reached or crossed the top
        if (i >= cost.size()) return 0;

        // Already calculated
        if (dp[i] != -1) return dp[i];

        // Take 1 step or 2 steps
        dp[i] = cost[i] + min(solve(i + 1, cost, dp), solve(i + 2, cost, dp));

        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n, -1);

        return min(solve(0, cost, dp), solve(1, cost, dp));
    }
};