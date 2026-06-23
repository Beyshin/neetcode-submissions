class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index_map;
        int n = nums.size();

        for(int i{}; i<n; i++){
            int remaining = target - nums[i];
            if(index_map.contains(remaining)){
                return {index_map[remaining], i};
            }
            index_map[nums[i]] = i;
        }

        return {-1, -1};
    };
};
