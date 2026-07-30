class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;

        for (int i = 0; i <= nums.size() - k; i++) {

            int maxi = nums[i];

            for (int j = i; j < i + k; j++) {
                maxi = max(maxi, nums[j]);
            }

            ans.push_back(maxi);
        }

        return ans;
    }
};