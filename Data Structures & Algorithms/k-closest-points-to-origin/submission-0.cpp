class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        struct custom_predicate_t{
            bool operator()(const vector<int> a, const vector<int> b) const {
                auto a_dist = a[0]*a[0] + a[1]*a[1];
                auto b_dist = b[0]*b[0] + b[1]*b[1];

                return a_dist < b_dist;     
            }
        };

        priority_queue<vector<int>, vector<vector<int>>, custom_predicate_t> pq;
        vector<vector<int>> ans_vec;

        for(const vector<int>& point : points){
            pq.push(point);
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans_vec.push_back(pq.top());
            pq.pop();
        }

        return ans_vec;

    }
};
