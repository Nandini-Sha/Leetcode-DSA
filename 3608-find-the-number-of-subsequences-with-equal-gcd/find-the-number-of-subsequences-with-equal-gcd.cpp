class Solution {
public:
    vector<vector<vector<int>>> dp;
    const int MOD = 1e9 + 7;
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n + 1, vector<vector<int>>(201, vector<int>(201, -1)));
        
        
        return dfs(0,0,0,n,nums);
    }
    int dfs(int i, int gcda, int gcdb, int n, vector<int>& nums){
        if(i == n){
            return (gcda != 0 && gcda == gcdb);
        }

        if(dp[i][gcda][gcdb]!=-1) return dp[i][gcda][gcdb];

        return dp[i][gcda][gcdb] = 
            ((dfs(i+1,gcd(gcda,nums[i]),gcdb,n,nums) + 
            dfs(i+1,gcda,gcd(gcdb,nums[i]),n,nums))%MOD + 
            dfs(i+1,gcda,gcdb,n,nums))%MOD ;

    }
};