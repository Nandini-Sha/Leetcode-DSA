class Solution {
private:
    int maxArea = 0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    int tempArea = 0;
                    formisland(grid,i,j, tempArea);

                }
            }
        }

        return maxArea;
    }
    void formisland(vector<vector<int>>& grid, int i, int j, int &area){
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = -1;
        area++;
        maxArea = max(maxArea,area);
        if(i+1<m && grid[i+1][j] == 1){
            formisland(grid,i+1,j, area);
        }
        if(j+1<n && grid[i][j+1] == 1){
            formisland(grid,i,j+1, area);
        }
        if(i-1>=0 && grid[i-1][j] == 1){
            formisland(grid,i-1,j, area);
        }
        if(j-1>=0 && grid[i][j-1] == 1){
            formisland(grid,i,j-1, area);
        }
    }
};