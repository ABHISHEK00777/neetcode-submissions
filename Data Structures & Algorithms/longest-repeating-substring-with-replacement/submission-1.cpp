class Solution {
public:
    int characterReplacement(string s, int k) {

        int freq[26] = {0};

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // Include current character
            freq[s[right] - 'A']++;

            // Update the maximum frequency seen
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Shrink left if exceeding max replacement
            int currWindow = right - left + 1;
            while (currWindow - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
                currWindow = right - left + 1;
            }

            // Current window is valid
            ans = max(ans, currWindow);
        }

        return ans;
    }
};