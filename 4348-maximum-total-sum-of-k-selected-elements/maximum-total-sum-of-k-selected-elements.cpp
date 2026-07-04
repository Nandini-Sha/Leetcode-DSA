class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i = k;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        int a = 0;
        priority_queue<int> bq;
        while(!pq.empty()){
            a = pq.top();
            pq.pop();
            bq.push(a);
        }
        long long sum = 0;
        while(!bq.empty()){
            a = bq.top();
            bq.pop();
            if(mul>1){
                sum+=1LL*a*mul;
                mul--;
            }
            else sum+=1ll*a;
        }

        return sum;
    }
};