class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int otherNum = target - nums[i];
            if (mp.find(otherNum) != mp.end()) {
                return {mp[otherNum], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
