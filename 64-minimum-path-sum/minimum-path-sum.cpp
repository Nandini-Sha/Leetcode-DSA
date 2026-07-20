class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m);
        vector<int> curr(m);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i==0 && j==0) curr[j] = grid[i][j];
                else if(i==0) curr[j] = curr[j-1] + grid[i][j];
                else if(j==0) curr[j] = prev[j] + grid[i][j];
                else{
                    curr[j] = min(curr[j-1],prev[j]) + grid[i][j];
                }
                prev = curr;
            }
        }

        return curr[m-1];
    }
};