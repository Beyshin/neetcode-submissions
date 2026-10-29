class Solution {
public:

    int dfs(vector<vector<int>>& grid, int x, int y){
        int m = grid.size(), n = grid[0].size();

        if(x >= m || x < 0 || y < 0 || y >= n || grid[x][y] == 1) return 0;

        if(x == m-1 && y == n-1) return 1;
        grid[x][y] = 1;

        int paths =  dfs(grid, x+1, y) + dfs(grid, x-1, y) + dfs(grid,x, y+1) + dfs(grid, x, y-1);

        grid[x][y] = 0;

        return paths;

    }

    int countPaths(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0);
    }
};
