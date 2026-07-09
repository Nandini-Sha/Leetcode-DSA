class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int take0 = nums[0];    
        int prev2 = 0;
        int temp;
        for(int i = 1;i<n-1;i++){
            temp = nums[i];
            if(i>1) temp+=prev2;
            prev2 = take0;
            take0 = max(temp,take0);
            
        }

        int nottake0 = nums[1];
        prev2 = 0;
        for(int i = 2;i<n;i++){
            temp = nums[i];
            if(i>2) temp+=prev2;
            prev2 = nottake0;
            nottake0 = max(temp,prev2);
        }
        
        return max(take0,nottake0);
    }

};