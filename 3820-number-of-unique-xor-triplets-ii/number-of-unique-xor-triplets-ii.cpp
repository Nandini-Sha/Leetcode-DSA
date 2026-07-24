class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int Max = 20448;
        vector<bool> XOR(Max+1,false);
        vector<bool> Final_XOR(Max+1,false);
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                XOR[nums[i]^nums[j]] = true;
            }
        }
        for(int i = 0;i<Max+1;i++){
            if(XOR[i]){
                for(int j = 0;j<n;j++){
                    Final_XOR[i^nums[j]] = true;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<Max+1;i++){
            if(Final_XOR[i]) ans++;
        }
        return ans;
    }
};
