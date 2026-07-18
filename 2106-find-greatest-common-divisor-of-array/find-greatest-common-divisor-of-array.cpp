class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smolll = INT_MAX;
        int laargee = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<smolll)  smolll = nums[i];
            if(nums[i]>laargee) laargee = nums[i];
        }

        return gcd(smolll,laargee);

    }
};