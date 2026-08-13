class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if (n % groupSize != 0)
            return false;

        map<int, int> freq;

        // Frequency of each card
        for (int card : hand) {
            freq[card]++;
        }

        while (!freq.empty()) {

            // Smallest available card
            int start = freq.begin()->first;

            // Build group: start, start+1, start+2...
            for (int x = start; x < start + groupSize; x++) {

                if (freq.find(x) == freq.end())
                    return false;

                freq[x]--;

                if (freq[x] == 0)
                    freq.erase(x);
            }
        }

        return true;
    }
};