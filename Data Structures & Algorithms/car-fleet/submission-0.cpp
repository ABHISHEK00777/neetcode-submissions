class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();

        vector<pair<int, double>> cars;

        // Store {position, time}
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];

            cars.push_back({position[i], time});
        }

        // Closest to target first
        sort(cars.begin(), cars.end(),
             [](const auto& a, const auto& b) {
                 return a.first > b.first;
             });

        int fleets = 0;
        double lastFleetTime = -1;

        for (int i = 0; i < n; i++) {

            double currentTime = cars[i].second;

            // Current car cannot catch fleet ahead
            if (currentTime > lastFleetTime) {
                fleets++;
                lastFleetTime = currentTime;
            }

            // Otherwise:
            // currentTime <= lastFleetTime
            // current car joins the existing fleet
        }

        return fleets;
    }
};