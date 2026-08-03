class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n,-1);
        dfs(0, n, stoneValue, dp);

        if(dp[0]>0) return "Alice";
        if(dp[0]<0) return "Bob";
        return "Tie";
    }
    int dfs(int i, int& n, vector<int>& stoneValue, vector<int>& dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int one = stoneValue[i] - dfs(i+1,n,stoneValue, dp);
        dp[i] = one;
        if(i+1<n) {
            int two = stoneValue[i] + stoneValue[i+1] - dfs(i+2,n,stoneValue, dp);
            dp[i] = max(dp[i],two);
        }
        if(i+2<n){ 
            int three = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dfs(i+3,n,stoneValue, dp);
            dp[i] = max(dp[i],three);
        }

        return dp[i];
    }
};