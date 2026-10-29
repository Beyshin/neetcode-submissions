class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        size_t n = nums.size();
        if(n == 1) return true;

        sort(nums.begin(), nums.end());

        for(size_t i =0; i<n-1; i++){
            if(nums[i+1] - nums[i] != 1) return false;
        }

        return true;
    }
};
