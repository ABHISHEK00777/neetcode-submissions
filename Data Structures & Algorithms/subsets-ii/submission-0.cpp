class Solution {
public:
    vector<vector<int>> ans;

    void solve(int start, vector<int>& nums, vector<int>& temp) {
        ans.push_back(temp);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicate at the same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            // Pick
            temp.push_back(nums[i]);

            solve(i + 1, nums, temp);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        solve(0, nums, temp);

        return ans;
    }
};