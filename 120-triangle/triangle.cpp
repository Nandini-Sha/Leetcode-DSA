class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n);
        vector<int> temp(n);
        for(int i = 0;i<n;i++){
            for(int k = 0;k<=i;k++){
                if(i==0 && k==0) dp[k] = triangle[i][k];
                else if(k==0) dp[k] = temp[k] + triangle[i][k];
                else if(k==i) dp[k] = temp[k-1] + triangle[i][k];
                else{
                    dp[k] = min(temp[k-1],temp[k]) + triangle[i][k];
                }
            }
            temp = dp;
        }

        return *min_element(dp.begin(),dp.end());
    }
};