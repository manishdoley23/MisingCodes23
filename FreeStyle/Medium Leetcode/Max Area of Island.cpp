//https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid){
        int r = grid.size();
        int c = grid[0].size();
        
        if(i < 0 || j < 0 || i >= r || j >= c || grid[i][j] != 1){
            return 0;
        }
        
        grid[i][j] = 2;
        return (1 + dfs(i+1, j, grid) + dfs(i-1, j, grid) + dfs(i, j+1, grid) + dfs(i, j-1, grid));
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int r = grid.size();
        int c = grid[0].size();
        
        int res = 0;
        
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(grid[i][j] == 1){
                    res = max(res, dfs(i, j, grid));
                }
            }
        }
        
        return res;
    }
};
