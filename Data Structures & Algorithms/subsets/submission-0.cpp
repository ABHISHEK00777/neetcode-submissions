class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int>& nums, vector<int>& temp) {
        // Base case
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Pick
        temp.push_back(nums[i]);
        solve(i + 1, nums, temp);

        // Backtrack
        temp.pop_back();

        // Not Pick
        solve(i + 1, nums, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0, nums, temp);
        return ans;
    }
};