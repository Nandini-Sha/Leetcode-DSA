class Solution {
public:
    vector<vector<int>> dp;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp.resize(m,vector<int> (n,-1));
        dfs(m-1, n-1, m, n, obstacleGrid);

        return dp[m-1][n-1];
    }
    int dfs(int i, int j, int m, int n, vector<vector<int>>& arr){
        if(i < 0 || j < 0) return 0;

        if(arr[i][j] == 1) {
            dp[i][j] = 0;
            return dp[i][j];
        }

        if(i == 0 && j == 0) {
            dp[i][j] = 1;
            return dp[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = dfs(i-1, j, m, n, arr) + dfs(i, j-1, m, n, arr);
    }
};