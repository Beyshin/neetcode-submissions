class Solution {
public:


    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        int curr_turn = 0;
        int fresh = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++)
                if(grid[i][j] == 2) q.push({i, j, curr_turn});
                else if (grid[i][j]==1) fresh++;
        }
        
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            vector<int> data = q.front();
            int x = data[0];
            int y = data[1];
            int turn = data[2];
            q.pop();
            curr_turn = turn;

            for(auto& [dx, dy] : directions){
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    q.push({nx,ny, turn+1});
                    fresh--;
                }
            }
        }
        return fresh > 0 ? -1 : curr_turn;
    }
};
