class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        return dfs(nums, dp, n-1);
    }
    int dfs(vector<int>& nums, vector<int>& dp, int ind){
        if(ind<0) return 0;
        if(dp[ind] == -1){
            dp[ind] = nums[ind] + dfs(nums, dp, ind-2);
            dp[ind] = max(dp[ind],dfs(nums, dp, ind-1));
        }

        return dp[ind];
    }
};