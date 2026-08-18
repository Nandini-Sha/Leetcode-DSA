class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==k) return *max_element(nums.begin(),nums.end());
        int ans = -1;
        if(k==1){
            unordered_map<int,int> mp;
            for(int i = 0;i<n;i++){
                mp[nums[i]]++;
            }
            for (int x : nums) {
                if (mp[x] == 1) {
                    ans = max(ans, x);
                }
            }
            
        }
        else{
            int cnt1 = 0,  cnt2 = 0;
            for(int i = 0;i<n;i++){
                if(nums[i]==nums[0]) cnt1++;
                if(nums[i]==nums[n-1]) cnt2++;
            }
            if(cnt1 == 1){
                ans = max(ans,nums[0]);
            }
            if(cnt2 == 1){
                ans = max(ans,nums[n-1]);
            }

            }
            
            return ans;    
    }
};