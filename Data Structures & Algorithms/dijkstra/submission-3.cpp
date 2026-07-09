class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, int> ans(n);

        for(size_t i = 0; i<n;i++){
            ans[i] = INT_MAX;
        }
        ans[src]=0;

        vector<vector<pair<int, int>>> adj(n); // {u, distance}

        for(const vector<int>& e : edges){
            adj[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {curr_distance, v}
        pq.push({0, src});

        while(!pq.empty()){
            const auto [curr_dist, u] = pq.top();
            pq.pop();

            if(curr_dist > ans[u]) continue;

            for(const auto& neighbor : adj[u]){
                auto [v, dist] = neighbor;
                if(ans[u] + dist < ans[v]){
                    ans[v] = ans[u] + dist;
                    pq.push({ans[v], v});
                }
            }
        }

        for(size_t i = 0; i<n; i++){
            if(ans[i] == INT_MAX) ans[i] = -1;
        }

        return ans;
    }
};
