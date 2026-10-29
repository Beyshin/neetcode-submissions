class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
       long long total_sum = 0;
       int n = nums.size();
       for(auto num : nums){
            total_sum += num;
       }
        
        long long curr_pre = 0;
       long long ans = LLONG_MIN;

        for(size_t i = 0; i<n; ++i){
            curr_pre += nums[i];

            long long curr_suff = total_sum - curr_pre + nums[i];
            long long curr_max = max(curr_suff, curr_pre);
            ans = max(curr_max, ans);
        }

        return ans;
    }
};
