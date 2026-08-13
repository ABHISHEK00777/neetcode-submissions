class Solution {
public:

    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        if (n <= 1)
            return 0;

        // Sort by ending time
        sort(intervals.begin(), intervals.end(), compare);

        int removed = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < n; i++) {

            // Overlap
            if (intervals[i][0] < prevEnd) {
                removed++;
            }
            else {
                // Keep this interval
                prevEnd = intervals[i][1];
            }
        }

        return removed;
    }
};