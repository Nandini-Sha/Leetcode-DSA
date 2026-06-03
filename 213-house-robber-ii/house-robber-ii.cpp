class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int r1 = 0, r2 = 0;
        int crr = 0;
        for(int i = 0;i<nums.size()-1;i++){
            crr = max(r1+nums[i],r2);
            r1 = r2;
            r2 = crr;
        }
        int a = max(r1,r2);
        r1 = 0, r2 = 0;
        for(int i = 1;i<nums.size();i++){
            crr = max(r1+nums[i],r2);
            r1 = r2;
            r2 = crr;
        }
        int b = max(r1,r2);
        return max(a,b);
    }
};