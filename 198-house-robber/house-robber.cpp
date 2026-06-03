class Solution {
public:
    int rob(vector<int>& nums) {
        int r1=0,r2=0;
        for(auto n:nums){
            int curr = max(r1+n,r2);
            r1 = r2;
            r2 = curr;
        }

        return max(r1,r2);
    }
};