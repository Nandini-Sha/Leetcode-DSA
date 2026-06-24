class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(idx==candidates.size() || target<0){
            return;
        }

        solve(idx+1, candidates, target, temp, res);

            temp.push_back(candidates[idx]);
            solve(idx, candidates, target-candidates[idx], temp, res);
            temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int sum = 0;
        solve(0, candidates, target, temp, res);

        return res;
        
    }
};