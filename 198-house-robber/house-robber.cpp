class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        dp.resize(nums.size(),-1);
        if(nums.size()<2) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2;i<nums.size();i++){
            dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
            
        }

        return max(dp[nums.size()-2],dp[nums.size()-1]);
    }
};