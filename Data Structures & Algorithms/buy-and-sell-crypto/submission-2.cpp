class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int maxProfit = 0;

        while (right < prices.size()) {
            if (prices[right] > prices[left]) {
                maxProfit = max(maxProfit, prices[right] - prices[left]);
            } else {
                left = right;
            }

            right++;
        }

        return maxProfit;
    }
};
