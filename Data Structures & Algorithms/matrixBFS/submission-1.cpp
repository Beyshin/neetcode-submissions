class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int m = grid.size(), n = grid[0].size();
        deque<vector<int>> q;
        int curr_road = 0;
        q.push_back({0,0,0});
        grid[0][0] = 1;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()){
            vector<int> point = q.front();
            q.pop_front();
            int x = point[0], y = point[1], dist = point[2];

            if(x == m-1 && y == n-1) return dist;

            for(const auto& dir : directions){
                int nx = x + dir.first;
                int ny = y + dir.second;

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    q.push_back({nx, ny, dist + 1});
                }
            }
            

        }

        cout << "checked all roads" << endl;

        return -1;
    }
};
