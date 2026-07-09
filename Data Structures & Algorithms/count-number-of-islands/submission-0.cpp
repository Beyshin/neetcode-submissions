class Solution {
public:

    void dfs(vector<vector<char>>& grid, int x, int y){
        if(grid[x][y] == '1'){
            grid[x][y] = '0';
        }else{
            return;
        }

        if(x != 0) dfs(grid, x-1, y);
        if(y != 0) dfs(grid, x, y-1);
        if(x != grid.size()-1) dfs(grid, x+1, y);
        if(y != grid[0].size()-1) dfs(grid, x, y+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        for(size_t i{}; i<grid.size(); i++){
            for(size_t j{}; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    counter++;
                }
            }
        }

        return counter;
    }
};
