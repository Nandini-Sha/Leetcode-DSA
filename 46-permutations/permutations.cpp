class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> track(n,false);
        vector<int> temp;
        dfs(nums,n, temp, track);
        return res;
    }

    void dfs(vector<int> &nums, int n, vector<int> &temp, vector<bool> &track){
        if(temp.size() == n){
            res.push_back(temp);
            return;
        }
        for(int i = 0;i<n;i++){
            if(!track[i]){
                temp.push_back(nums[i]);
                track[i] = true;
                dfs(nums, n, temp, track);
                temp.pop_back();
                track[i] = false;
            }
        }
    }
};