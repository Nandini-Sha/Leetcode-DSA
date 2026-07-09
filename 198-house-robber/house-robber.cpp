class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int cur = nums[0];
        int prev = 0;
        int temp;
        for(int i = 1;i<n;i++){
            temp = nums[i];
            if(i>1) temp+=prev;
            prev = cur;
            cur = max(cur,temp);
        }

        return cur;
    }
};