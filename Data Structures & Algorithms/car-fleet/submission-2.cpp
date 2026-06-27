class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vec;
        int count = 0;

        if(position.size() == 1) return 1;

        for(size_t i{}; i<position.size(); i++){
            vec.push_back({position[i], speed[i]});
        }

        sort(vec.begin(), vec.end(), [&](const pair<int, int> a, const pair<int, int> b){
            return a.first < b.first;
        });

        double slowest_time_ahead = 0.0;

        for(int i = vec.size() - 1; i >= 0; i--){
            
            int distance_left = target - vec[i].first;
            double hours = (double)distance_left / vec[i].second;

            if(hours > slowest_time_ahead){
                count++;
                slowest_time_ahead = hours;
            }
            

        }

        return count;
    }
};
