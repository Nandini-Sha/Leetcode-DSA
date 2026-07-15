class Solution {
public:
    vector<vector<int>> dp;
    int uniquePaths(int m, int n) {
        if(m==1 && n==1) return 1;
        dp.resize(m, vector<int>(n, -1));
        dfs(m-1,n-1);
        return dp[m-1][n-1];
    }
    int dfs(int i, int j){
        if (i < 0 || j < 0)
            return 0;
        if(i==0 && j==0){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = dfs(i-1,j) + dfs(i,j-1);
    }
};