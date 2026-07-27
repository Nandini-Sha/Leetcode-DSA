class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max, prev;
        if(nums[0]<nums[1]){
            max = nums[1];
            prev = nums[0];
        }
        else{
            max = nums[0];
            prev = nums[1];
        }
        for(int i = 2;i<nums.size();i++){
            if(nums[i]>=max){
                prev = max;
                max = nums[i];
            }
            else if(nums[i]>prev){
                prev = nums[i];
            }
        }
        return (max-1)*(prev-1);
    }
};