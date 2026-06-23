class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> index_map;
        int n = nums.size();

        for(int i{}; i<n; i++){
            int remaining = target - nums[i];
            if(index_map.contains(remaining)){
                return {index_map[remaining][0], i};
            }
            index_map[nums[i]].push_back(i);
        }

        return {-1, -1};
    };
};
