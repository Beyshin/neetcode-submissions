class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map_cnt;

        for(const int num : nums){
            map_cnt[num]++;
        }

        vector<pair<int, int>> elems(map_cnt.begin(), map_cnt.end());

        sort(elems.begin(), elems.end(), [&](const pair<int, int> a, const pair<int, int> b){
            return a.second < b.second;
        });

        vector<pair<int,int>> vec(elems.end()-k, elems.end());
        vector<int> ans;
        for(auto para : vec){
            ans.push_back(para.first);
        }
        return ans;
        
    }
};
