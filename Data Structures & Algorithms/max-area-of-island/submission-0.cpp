class Solution {
public:
    int explore(vector<vector<int>>& grid, int x, int y){
        int m = grid.size(), n = grid[0].size();
        if(x >= m || x < 0 || y >= n || y < 0 || grid[x][y] == 0){
            return 0;
        }
        
        grid[x][y] = 0;

        return 1 + explore(grid, x+1, y) + explore(grid, x-1, y) + explore(grid, x, y+1) + explore(grid, x, y-1);
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int m = grid.size(), n = grid[0].size();
    
        for(size_t i = 0; i<m; i++){
            for(size_t j = 0; j<n; j++){
                if(grid[i][j]){
                    max_area = max(max_area, explore(grid, i, j));
                }
            }
        }

        return max_area;
    }
};
