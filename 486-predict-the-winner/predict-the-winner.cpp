class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return (dfs(0,n-1,nums,dp)>=0);
    }

    int dfs(int l, int r, vector<int>& nums, vector<vector<int>>& dp){
        if(l==r) return nums[l];
        if(dp[l][r]!=-1) return dp[l][r];
        int left = nums[l]-dfs(l+1,r,nums,dp);
        int right = nums[r]-dfs(l,r-1,nums,dp);
        dp[l][r] = max(left,right);
        return dp[l][r];
    }
};