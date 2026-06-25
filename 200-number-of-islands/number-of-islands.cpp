class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '#') continue;
                if(grid[i][j] == '1'){
                    ans++;
                    formisland(grid,i,j);

                }
            }
        }

        return ans;
    }
    void formisland(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = '#';
        if(i+1<m && grid[i+1][j] == '1'){
            formisland(grid,i+1,j);
        }
        if(j+1<n && grid[i][j+1] == '1'){
            formisland(grid,i,j+1);
        }
        if(i-1>=0 && grid[i-1][j] == '1'){
            formisland(grid,i-1,j);
        }
        if(j-1>=0 && grid[i][j-1] == '1'){
            formisland(grid,i,j-1);
        }
    }
};