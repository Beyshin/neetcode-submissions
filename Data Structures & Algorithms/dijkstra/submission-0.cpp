class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
       vector<vector<pair<int,int>>> adj(n);
       unordered_map<int, int> distances;

        for(int i = 0; i<n; i++){
            distances[i] = INT_MAX;
        }
        distances[src] = 0;

        for(const auto& e : edges){
            adj[e[0]].push_back({e[1], e[2]});
        };

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while(!pq.empty()){
            auto [curr_dist, u] = pq.top();
            pq.pop();

            if(curr_dist > distances[u]) continue;

            cout << "Checking neighbors for " << u << endl;
            for(auto& neighbor : adj[u]){
                int v = neighbor.first;
                int distance_to = neighbor.second;
                cout << "\t" << "Neighbor " << v << " Distance " << distance_to << endl;
                if(distances[u] + distance_to < distances[v]){
                    distances[v] = distances[u] + distance_to;
                    pq.push({distances[v], v});
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(distances[i] == INT_MAX) distances[i] = -1;
        }

        return distances;
    }
};
