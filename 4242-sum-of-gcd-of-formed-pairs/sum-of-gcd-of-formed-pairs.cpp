class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixeGcd(n,nums[0]);
        for(int i = 1;i<n;i++){
            if(nums[i]>prefixeGcd[i-1]) prefixeGcd[i] = nums[i];
            else prefixeGcd[i] = prefixeGcd[i-1];
        }
        for(int i = 0;i<n;i++){
            prefixeGcd[i] = gcd(prefixeGcd[i],nums[i]);
        }
        sort(prefixeGcd.begin(),prefixeGcd.end());
        long long sum = 0;
        for(int i = 0;i<=n/2-1;i++){
            sum+= gcd(prefixeGcd[i],prefixeGcd[n-1-i]);
        }

        return sum;
    }
};