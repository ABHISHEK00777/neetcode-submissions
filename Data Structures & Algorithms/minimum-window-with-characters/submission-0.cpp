class Solution {
public:
    string minWindow(string s, string t) {

        int target[128] = {0};

        for(char ch : t)
            target[ch]++;

        int minLen = INT_MAX;
        int start = -1;

        for(int i = 0; i < s.size(); i++) {

            int window[128] = {0};

            for(int j = i; j < s.size(); j++) {

                window[s[j]]++;

                bool valid = true;

                for(int c = 0; c < 128; c++) {
                    if(window[c] < target[c]) {
                        valid = false;
                        break;
                    }
                }

                if(valid) {

                    if(j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        if(start == -1)
            return "";

        return s.substr(start, minLen);
    }
};