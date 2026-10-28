class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);

        int idx = 0;
        for(int i = 0; i<2; i++){
            for(int j = 0; j<n; j++){
                ans[idx] = nums[j];
                idx++;
            }
        }

        return ans;
    }
};