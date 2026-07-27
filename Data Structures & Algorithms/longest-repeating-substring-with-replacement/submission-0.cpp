class Solution {
public:
    int characterReplacement(string s, int k) {

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            int freq[26] = {0};

            for (int j = i; j < s.size(); j++) {

                freq[s[j] - 'A']++;

                int maxFreq = 0;

                for (int c = 0; c < 26; c++)
                    maxFreq = max(maxFreq, freq[c]);

                int window = j - i + 1;

                if (window - maxFreq <= k)
                    ans = max(ans, window);
            }
        }

        return ans;
    }
};